#include "BitcoinExchange.hpp"

int main(void) { 
	BitcoinExchange btc(DB_PATH);

	btc.printValue("     2019-12-13 |     3      ");
}