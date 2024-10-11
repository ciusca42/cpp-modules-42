#include "BitcoinExchange.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>

void trimSpace(std::string &str) {
	return ;
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

time_t parseDate(const char *dateString) {
    struct tm tmStruct = {};  // Initialize to zero to avoid garbage values
    // Parse the date string into the tmStruct
    if (strptime(dateString, "%Y-%m-%d", &tmStruct) == NULL) {
        std::cerr << "Error parsing date" << std::endl;
        return -1;  // Handle error (e.g., invalid date format)
    }
    // Create time_t object
    return mktime(&tmStruct);
}

std::string dateTime(time_t time) {
    char buffer[90];
    struct tm* timeinfo = localtime(&time);
    // Format the date into a strinsecondg
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return std::string(buffer);
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

int	parseNumber(double btc) {
	if (btc < 0) {
		std::cerr << "invalid btc numberd\n";
		return -1;
	}
	if (btc > INT_MAX) {
		std::cerr << "btc number too big\n";
		return -1;
	}
	return 0;
}

void BitcoinExchange::printValue(std::ifstream &inputFile) {
	std::string		line;
	time_t			date;
	double			btcN;
	int				pos;

	std::map<time_t, double>::iterator dbIt;
	getline(inputFile, line);
	while(getline(inputFile, line)) {
		pos = line.find("|");
		if (pos == -1) {
			std::cerr << "invalid format\n";
			continue;
		}
		date = parseDate(line.substr(0, pos).c_str());
		dbIt = this->db.find(date);
		btcN = atof(line.substr(pos + 1).c_str());
		if (parseNumber(btcN) < 0){
			continue;
		}
		if (dbIt != this->db.end()) {
			std::cout << "actual value: " << dbIt->second * btcN << '\n';
			continue;
		}
		
		dbIt = this->db.lower_bound(date);
		if (dbIt == this->db.begin()) {
			std::cerr << "date too low\n";
			continue ;
		}
		dbIt--;
		std::cout << "value: " << dbIt->second * btcN << '\n';
	}
	// std::cout << "db: " << this->db[key] * atof(value.c_str()) << '\n';
}