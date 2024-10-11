#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream> // IWYU pragma: keep
#include <string>
#include <map>


#define DB_PATH "db/data.csv"

typedef std::map<std::string, double>::iterator iter;

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		BitcoinExchange & operator=(const BitcoinExchange & obj);

		void printValue(std::ifstream &inputFile);

	private:
		int setDb(std::ifstream &dbFile);

		/* don't need maybe */
		std::map<std::string, double> dateInput;
		/* ---------------- */
		
		std::map<time_t, double> db;	
};

#endif