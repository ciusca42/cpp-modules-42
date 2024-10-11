#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) { 
	BitcoinExchange btc(argv[1]);
	std::ifstream inputFile;
	std::string		line;

	if (argc != 2) {
		std::cout << "Usage: ./btc < input file >\n";
		return 0;
	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open()) {
		std::cout << "could not open the file\n";
		return 0;
	}

	btc.printValue();

	return 0;
}