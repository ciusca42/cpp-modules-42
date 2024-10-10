#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) { 
	BitcoinExchange btc(DB_PATH);
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
	// getline(inputFile, line);
	// while (getline(inputFile, line)) {
	// 	btc.printValue(line);
	// }
	btc.printValue("2011-01-03 | 3");
	btc.printValue("2011-01-03 | 2");
	btc.printValue("2011-01-03 | 1");
	btc.printValue("2011-01-03 | 1.2");
	btc.printValue("2011-01-09 | 1");

	return 0;
}