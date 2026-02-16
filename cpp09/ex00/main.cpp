#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	BitcoinExchange btc;

	if (!btc.loadDatabase("data.csv")) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	btc.processInputFile(argv[1]);
	return 0;
}
