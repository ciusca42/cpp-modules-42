#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

void trimSpace(std::string &str) {
	return ;
	while (isspace(str[0]))
		str.erase(0, 1);
	while (isspace(str[str.length() - 1]))
		str.erase(str.length() - 1, 1);
}

BitcoinExchange::BitcoinExchange(std::string inputPath) {
	std::ifstream dbFile, inputFile;
	
	dbFile.open(DB_PATH);
	if (!dbFile.is_open())
		exit(1);

	inputFile.open(inputPath.c_str());
	if (!inputFile.is_open()) {
		dbFile.close();
		exit(1);
	}

	if (!this->setMap(dbFile, this->db, ",") || !this->setMap(inputFile, this->input, "|")) {
		dbFile.close();
		inputFile.close();
		std::cout << "error\n";
		exit(1);
	}
	dbFile.close();
	inputFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { 
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	this->db = obj.db;
	return *this;
}


void BitcoinExchange::tokenizeDate(std::string line, std::string delim, std::map<std::string, double> &mp) {
	std::string key, value;
	int			delimPos;

	delimPos = line.find(delim);
	key.insert(0, line, 0, delimPos);
	value.insert(0, line, delimPos + delim.length());
	mp[key] = atof(value.c_str());
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

int BitcoinExchange::setMap(std::ifstream &file, std::map<time_t, double> &mp, std::string delim) { 
	std::string line;
	std::string key, value;
	int			pos;

	getline(file, line);
	while (getline(file, line)) {
		pos = line.find(delim);
		if (pos == -1) {
			return 0;
		}
		key.insert(0, line, 0, pos);
		value.insert(0, line, pos + 1);
		// std::cout << "\ninit: " << key << '\n';
		mp[parseDate(key.c_str())] = atof(value.c_str());
		key.clear();
		value.clear();
	}
	return 1;
}

void BitcoinExchange::printValue() {
	
	std::stringstream	str;
	std::map<time_t, double>::iterator dbIt;

	std::cout << "size: " << this->input.size() << '\n';
	for (std::map<time_t, double>::iterator it = this->input.begin(); it != this->input.end(); *it++) {

		dbIt = this->db.find(it->first);
		if (dbIt != this->db.end()) {
			std::cout << "actual value: " << dbIt->second * it->second << '\n';
			continue;
		}
		
		dbIt = this->db.lower_bound(it->first);
		if (dbIt == this->db.begin()) {
			std::cerr << "date to low\n";
			continue ;
		}
		dbIt--;
		std::cout << "value: " << dbIt->second * it->second << '\n';
	}
	// std::cout << "db: " << this->db[key] * atof(value.c_str()) << '\n';
}