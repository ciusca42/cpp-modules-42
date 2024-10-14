#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

void trimSpace(std::string &str) {
	while (isspace(str[0]))
		str.erase(0, 1);
	while (isspace(str[str.length() - 1]))
		str.erase(str.length() - 1, 1);
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream dbFile;
	
	dbFile.open(DB_PATH);
	if (!dbFile.is_open())
		exit(1);

	if (!this->setDb(dbFile)) {
		dbFile.close();
		exit(1);
	}
	dbFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { 
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	this->db = obj.db;
	return *this;
}

time_t BitcoinExchange::parseDate(const char *dateString) {
    struct tm tmStruct = {};  // Initialize to zero to avoid garbage values
    // Parse the date string into the tmStruct
    if (strptime(dateString, "%Y-%m-%d", &tmStruct) == NULL) {
        std::cerr << "Error parsing date" << std::endl;
        return -1;  // Handle error (e.g., invalid date format)
    }
    // Create time_t object
    return mktime(&tmStruct);
}

std::string BitcoinExchange::formatDate(time_t time) {
	std::string dateFormat;
    char buffer[90];
    struct tm* timeinfo = localtime(&time);
    // Format the date into a string
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    dateFormat = std::string(buffer);
	return dateFormat = CYAN200 + dateFormat + RESET;
}

int BitcoinExchange::setDb(std::ifstream &file) { 
	std::string line;
	std::string key, value;
	int			pos;

	getline(file, line);
	while (getline(file, line)) {
		pos = line.find(",");
		if (pos == -1) {
			return 0;
		}
		key.insert(0, line, 0, pos);
		value.insert(0, line, pos + 1);
		// std::cout << "\ninit: " << key << '\n';
		this->db[parseDate(key.c_str())] = atof(value.c_str());
		key.clear();
		value.clear();
	}
	return 1;
}

void BitcoinExchange::error(const std::string msg) {
	std::cerr << ROSE300 << "Error: " << RESET;
	std::cerr << EMERALD200 << msg << '\n' << RESET;
}

float	BitcoinExchange::parseNumber(std::string line, int pos) {
	float				btc;
	std::string 		value;
	std::string			date;
	std::ostringstream	str;

	date = line.substr(0, pos);
	trimSpace(date);
	value = line.substr(pos+ 1);
	trimSpace(value);
	btc = atof(value.c_str());
	str << btc;
	if ((btc == 0 && value.length() > 1)) {
		error("bad input => " + date);
		return -1;
	}
	if (btc > 1000) {
		error("number too big");
		return -1;
	}
	if (btc < 0) {
		error("not a positive number");
		return -1;
	}
	return btc;
}

void BitcoinExchange::printValidDate(time_t date, float btcN, iterator dbIt) {
	std::cout << formatDate(date) << " => " << AMBER300 << btcN << RESET " = " << YELLOW200  << dbIt->second * btcN << '\n' << RESET;

}

void BitcoinExchange::printValue(std::ifstream &inputFile) {
	std::string		line;
	time_t			date;
	float			btcN;
	int				pos;
	int				i = 0;

	iterator dbIt;
	getline(inputFile, line);
	if (line != "date | value") {
		error("missing or invalid header");
		return ;
	}
	while(getline(inputFile, line)) {
		i++;
		trimSpace(line);
		std::cout << GREEN200 << i << ' ' << RESET;
		if (line == "") {
			std::cout << "'empty line'\n";
			continue;
		}
		pos = line.find("|");
		if (pos == -1) {
			error("bad input => " + line);
			continue;
		}
		date = parseDate(line.substr(0, pos).c_str());
		dbIt = this->db.find(date);
		btcN = parseNumber(line, pos);
		if (btcN < 0) {
			continue;
		}
		if (dbIt != this->db.end()) {
			printValidDate(date, btcN, dbIt);
			continue;
		}
		
		dbIt = this->db.lower_bound(date);
		if (dbIt == this->db.begin()) {
			std::cerr << "date too low\n";
			continue ;
		}
		dbIt--;
		printValidDate(date, btcN, dbIt);
	}
}