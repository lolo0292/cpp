#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool loadDatabase(const std::string& csvFile);
	void processInputFile(const std::string& inputFile) const;

private:
	std::map<std::string, double> _rates; // key: "YYYY-MM-DD", value: rate

	static std::string trim(const std::string& s);

	static bool isLeapYear(int year);
	static bool isValidDate(const std::string& date);

	static bool splitInputLine(const std::string& line, std::string& date, std::string& value);
	static bool parseNumberStrict(const std::string& s, double& out);

	bool getRateForDate(const std::string& date, double& outRate) const;
};

#endif
