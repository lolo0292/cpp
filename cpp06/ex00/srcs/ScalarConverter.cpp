#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <cmath>

namespace
{
	enum eType
	{
		T_CHAR,
		T_INT,
		T_FLOAT,
		T_DOUBLE,
		T_PSEUDO_FLOAT,
		T_PSEUDO_DOUBLE,
		T_INVALID
	};

	static bool isNan(double x) { return x != x; }

	static bool isInf(double x)
	{
		// Works well with strtod which returns +/-HUGE_VAL on overflow
		return (x == HUGE_VAL || x == -HUGE_VAL);
	}

	static bool isIntLiteral(const std::string &s)
	{
		size_t i = 0;
		if (s.empty())
			return false;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (i >= s.size())
			return false;
		for (; i < s.size(); i++)
		{
			if (!std::isdigit(static_cast<unsigned char>(s[i])))
				return false;
		}
		return true;
	}

	static bool isCharLiteral(const std::string &s)
	{
		// 'c'
		if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
			return true;
		// single non-digit character: a, Z, *
		if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
			return true;
		return false;
	}

	static bool endsWith(const std::string &s, const std::string &suffix)
	{
		if (s.size() < suffix.size())
			return false;
		return s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

	static eType detectType(const std::string &s)
	{
		if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
			return T_PSEUDO_FLOAT;
		if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
			return T_PSEUDO_DOUBLE;

		if (isCharLiteral(s))
			return T_CHAR;

		if (isIntLiteral(s))
			return T_INT;

		// Float with trailing 'f' (common form)
		if (endsWith(s, "f") && s.size() > 1)
		{
			std::string core = s.substr(0, s.size() - 1);
			char *end = 0;
			errno = 0;
			std::strtod(core.c_str(), &end);
			if (end && *end == '\0')
				return T_FLOAT;
		}

		// Double
		{
			char *end = 0;
			errno = 0;
			std::strtod(s.c_str(), &end);
			if (end && *end == '\0')
				return T_DOUBLE;
		}

		return T_INVALID;
	}

	static void printChar(double d)
	{
		std::cout << "char: ";
		if (isNan(d) || isInf(d))
		{
			std::cout << "impossible\n";
			return;
		}
		if (d < 0.0 || d > 127.0)
		{
			std::cout << "impossible\n";
			return;
		}
		char c = static_cast<char>(d);
		if (!std::isprint(static_cast<unsigned char>(c)))
		{
			std::cout << "Non displayable\n";
			return;
		}
		std::cout << "'" << c << "'\n";
	}

	static void printInt(double d)
	{
		std::cout << "int: ";
		if (isNan(d) || isInf(d))
		{
			std::cout << "impossible\n";
			return;
		}
		if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
			d > static_cast<double>(std::numeric_limits<int>::max()))
		{
			std::cout << "impossible\n";
			return;
		}
		std::cout << static_cast<int>(d) << "\n";
	}

	static bool hasZeroFraction(double d)
	{
		if (isNan(d) || isInf(d))
			return false;
		double intpart;
		double frac = std::modf(d, &intpart);
		return (frac == 0.0);
	}

	static void printFloat(double d)
	{
		std::cout << "float: ";

		// Pseudo / special cases
		if (isNan(d))
		{
			std::cout << "nanf\n";
			return;
		}
		if (isInf(d))
		{
			if (d < 0)
				std::cout << "-inff\n";
			else
				std::cout << "+inff\n";
			return;
		}

		// Range check for float (optional but nice)
		if (d > static_cast<double>(std::numeric_limits<float>::max()) ||
			d < -static_cast<double>(std::numeric_limits<float>::max()))
		{
			std::cout << "impossible\n";
			return;
		}

		float f = static_cast<float>(d);

		if (hasZeroFraction(d))
			std::cout << std::fixed << std::setprecision(1) << f << "f\n";
		else
			std::cout << std::fixed << std::setprecision( std::numeric_limits<float>::digits10 ) << f << "f\n";
	}

	static void printDouble(double d)
	{
		std::cout << "double: ";

		if (isNan(d))
		{
			std::cout << "nan\n";
			return;
		}
		if (isInf(d))
		{
			if (d < 0)
				std::cout << "-inf\n";
			else
				std::cout << "+inf\n";
			return;
		}

		if (hasZeroFraction(d))
			std::cout << std::fixed << std::setprecision(1) << d << "\n";
		else
			std::cout << std::fixed << std::setprecision( std::numeric_limits<double>::digits10 ) << d << "\n";
	}

	static double parseToDouble(eType t, const std::string &s, bool &ok)
	{
		ok = true;

		if (t == T_PSEUDO_FLOAT)
		{
			if (s == "nanf")
				return (0.0 / 0.0);
			if (s == "+inff" || s == "inff")
				return HUGE_VAL;
			return -HUGE_VAL;
		}
		if (t == T_PSEUDO_DOUBLE)
		{
			if (s == "nan")
				return (0.0 / 0.0);
			if (s == "+inf" || s == "inf")
				return HUGE_VAL;
			return -HUGE_VAL;
		}
		if (t == T_CHAR)
		{
			if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
				return static_cast<double>(s[1]);
			return static_cast<double>(s[0]);
		}
		if (t == T_INT)
		{
			// Use strtol to avoid UB if too large
			char *end = 0;
			errno = 0;
			long v = std::strtol(s.c_str(), &end, 10);
			if (errno == ERANGE || !end || *end != '\0')
			{
				ok = false;
				return 0.0;
			}
			return static_cast<double>(v);
		}
		if (t == T_FLOAT)
		{
			std::string core = s.substr(0, s.size() - 1);
			char *end = 0;
			errno = 0;
			double d = std::strtod(core.c_str(), &end);
			if (!end || *end != '\0')
			{
				ok = false;
				return 0.0;
			}
			// accept overflow as inf-like; will be printed as +/-inff
			return d;
		}
		if (t == T_DOUBLE)
		{
			char *end = 0;
			errno = 0;
			double d = std::strtod(s.c_str(), &end);
			if (!end || *end != '\0')
			{
				ok = false;
				return 0.0;
			}
			return d;
		}
		ok = false;
		return 0.0;
	}
}

// Private special members (not instantiable)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	eType type = detectType(literal);
	if (type == T_INVALID)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	bool ok = false;
	double d = parseToDouble(type, literal, ok);
	if (!ok)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
