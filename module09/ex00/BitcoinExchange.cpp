#include "BitcoinExchange.hpp"
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
		exit(0);

	inputFile.open(inputPath.c_str());
	if (!inputFile.is_open()) {
		dbFile.close();
		exit(0);
	}

	this->setDb(dbFile);
	// this->setInput(inputFile);
	dbFile.close();
	inputFile.close();
}

BitcoinExchange::~BitcoinExchange() {

}

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


void BitcoinExchange::setInput(std::ifstream &inputFile) {
	std::string line;
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		break;
	}
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

void BitcoinExchange::setDb(std::ifstream &dbFile) { 
	std::string line;

	getline(dbFile, line);
	while (getline(dbFile, line)) {
		
	}
}

void BitcoinExchange::printValue(std::string line) {
	std::string 		key, value;
	// double				nbBtc;
	time_t				date;
	std::stringstream	str;


	key.insert(0, line, 0, line.find("|"));
	
	value.insert(0, line, line.find("|") + 1);
	trimSpace(value);
	trimSpace(key);
	
	date = parseDate(key.c_str());
	if (date == -1)
		return ;
	std::map<std::string, double>::iterator it = this->db.find(dateTime(date));
	std::cout << "number: " << value << '\n';
	std::cout << "second: " << it->first << '\n';
	if (it != this->db.end()) {
		std::cout << "actual value: " << it->second * atof(value.c_str()) << '\n';
		return ;
	}

	it = this->db.lower_bound(key);
	if (it == this->db.begin())
		std::cerr << "date to low\n";
	std::cout << "value: " << --it->second * atof(value.c_str()) << '\n';
	// std::cout << "db: " << this->db[key] * atof(value.c_str()) << '\n';
}