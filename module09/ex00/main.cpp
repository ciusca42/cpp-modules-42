#include "BitcoinExchange.hpp"

int main(void) { 
	BitcoinExchange btc("data.csv");

	btc.printValue("data");
}