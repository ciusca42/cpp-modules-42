#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <ctime>
#include <fstream> // IWYU pragma: keep
#include <string>
#include <map>
#include "colors.hpp" // IWYU pragma: keep

typedef std::map<time_t, float>::iterator iterator;

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

		void error(const std::string msg);
		time_t parseDate(const char *dateSTring);
		std::string formatDate(time_t time);
		float parseNumber(std::string line, int pos);
		void printValidDate(time_t date, float btcN, iterator it);
		
		std::map<time_t, float> db;	
};

#endif