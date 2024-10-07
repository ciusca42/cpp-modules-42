#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream> // IWYU pragma: keep
#include <string>
#include <map>

typedef std::map<std::string, double>::iterator iter;

class BitcoinExchange {
	public:
		BitcoinExchange(std::string inputFile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		BitcoinExchange & operator=(const BitcoinExchange & obj);

		void printValue(std::string date);

	private:
		void setDb();
		void setInput(std::string &inputfile);

		std::string tokenizeDate(std::string &line, std::string delim);
		std::string parseDate(std::string &inputDate);
	
		std::map<std::string, double> db;
		std::map<std::string, double> dateInput;
};

#endif