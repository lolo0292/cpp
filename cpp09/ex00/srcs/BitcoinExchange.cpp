#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_rates = other._rates;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& s) {
	std::size_t i = 0;
	while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i])))
		++i;

	std::size_t j = s.size();
	while (j > i && std::isspace(static_cast<unsigned char>(s[j - 1])))
		--j;

	return s.substr(i, j - i);
}

bool BitcoinExchange::isLeapYear(int year) {
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	return (year % 4 == 0);
}

static bool allDigits(const std::string& s) {
	if (s.empty()) return false;
	for (std::size_t i = 0; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	const std::string ys = date.substr(0, 4);
	const std::string ms = date.substr(5, 2);
	const std::string ds = date.substr(8, 2);

	if (!allDigits(ys) || !allDigits(ms) || !allDigits(ds))
		return false;

	const int y = std::atoi(ys.c_str());
	const int m = std::atoi(ms.c_str());
	const int d = std::atoi(ds.c_str());

	if (m < 1 || m > 12) return false;
	if (d < 1) return false;

	int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (m == 2 && isLeapYear(y))
		mdays[1] = 29;

	if (d > mdays[m - 1]) return false;
	return true;
}

bool BitcoinExchange::parseNumberStrict(const std::string& s, double& out) {
	// strict: accept number with optional leading spaces, but reject junk after number
	const std::string t = trim(s);
	if (t.empty()) return false;

	char *end = 0;
	out = std::strtod(t.c_str(), &end);
	if (end == t.c_str())
		return false;

	while (*end) {
		if (!std::isspace(static_cast<unsigned char>(*end)))
			return false;
		++end;
	}
	return true;
}

bool BitcoinExchange::splitInputLine(const std::string& line, std::string& date, std::string& value) {
	// Expected: "date | value"
	const std::size_t pos = line.find('|');
	if (pos == std::string::npos)
		return false;

	date = trim(line.substr(0, pos));
	value = trim(line.substr(pos + 1));

	if (date.empty() || value.empty())
		return false;
	return true;
}

bool BitcoinExchange::loadDatabase(const std::string& csvFile) {
	std::ifstream in(csvFile.c_str());
	if (!in.is_open())
		return false;

	std::string line;
	if (!std::getline(in, line))
		return false;

	// header usually "date,exchange_rate"
	while (std::getline(in, line)) {
		if (line.empty())
			continue;

		const std::size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		const std::string date = trim(line.substr(0, comma));
		const std::string rateStr = trim(line.substr(comma + 1));

		if (!isValidDate(date))
			continue;

		double rate = 0.0;
		if (!parseNumberStrict(rateStr, rate))
			continue;

		_rates[date] = rate;
	}
	return !_rates.empty();
}

bool BitcoinExchange::getRateForDate(const std::string& date, double& outRate) const {
	if (_rates.empty())
		return false;

	// exact match
	std::map<std::string, double>::const_iterator it = _rates.find(date);
	if (it != _rates.end()) {
		outRate = it->second;
		return true;
	}

	// first key >= date
	it = _rates.lower_bound(date);

	// if date is earlier than the first DB date => no lower date exists
	if (it == _rates.begin()) {
		return false;
	}

	// closest lower date
	--it;
	outRate = it->second;
	return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) const {
	std::ifstream in(inputFile.c_str());
	if (!in.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	// Read header line (usually "date | value") but stay tolerant
	if (!std::getline(in, line))
		return;

	while (std::getline(in, line)) {
		if (line.empty())
			continue;

		std::string date;
		std::string valueStr;

		if (!splitInputLine(line, date, valueStr) || !isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = 0.0;
		if (!parseNumberStrict(valueStr, value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0.0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = 0.0;
		if (!getRateForDate(date, rate)) {
			// clearer than "bad input": date is valid but not covered by DB (too early)
			std::cerr << "Error: no rate available for date => " << date;
			if (!_rates.empty())
				std::cerr << " (earliest is " << _rates.begin()->first << ")";
			std::cerr << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
}
