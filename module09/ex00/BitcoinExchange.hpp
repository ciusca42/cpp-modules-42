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
		BitcoinExchange(std::string inputPath);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		BitcoinExchange & operator=(const BitcoinExchange & obj);

		void printValue(std::string line);

	private:
		void setDb(std::ifstream &dbFile);

		/* don't need maybe */
		void setInput(std::ifstream &inputfile);
		void tokenizeDate(std::string line, std::string delim, std::map<std::string, double> &mp);
		std::map<std::string, double> dateInput;
		/* ---------------- */
		
		std::map<time_t, double> db;
		// time_t	firstDate;
		
};

#endif