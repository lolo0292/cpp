#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

static void run_one(int i, const std::string &lit)
{
	std::cout << "\n=== Test " << i << " : \"" << lit << "\" ===\n";
	ScalarConverter::convert(lit);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}

	const std::string tests[] = {
		"0",        // int -> char non displayable
		"42",       // int -> char '*'
		"a",        // char -> int/float/double
		"42.0f",    // float
		"4.2",      // double with fraction
		"nan",      // pseudo double
		"+inff",    // pseudo float
		"2147483648", // int overflow
		"-inf",     // pseudo double
		"abc"       // invalid
	};

	const int n = (int)(sizeof(tests) / sizeof(tests[0]));
	for (int i = 0; i < n; i++)
		run_one(i + 1, tests[i]);

	return 0;
}
