#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>

int main(int argc, char **argv) { 
	BitcoinExchange btc;
	std::ifstream inputFile;
	std::string		line;

	if (argc != 2) {
		std::cout << "\n" << BLUE200 << "Usage: ./btc < input file >\n\n" << RESET;
		return 0;
	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << ROSE300 << "\ncould not open the file\n\n" RESET;
		return 0;
	}

	btc.printValue(inputFile);

	return 0;
}