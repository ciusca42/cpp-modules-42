#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

void trimSpace(std::string &str) { 
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
	this->setInput(inputFile);
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

void BitcoinExchange::setDb(std::ifstream &dbFile) { 
	std::string		line;

	getline(dbFile, line);
	while (getline(dbFile, line)) {
		tokenizeDate(line, ",", this->db);
	}
}

void BitcoinExchange::setInput(std::ifstream &inputFile) {
	std::string line;
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		
	}
}

void BitcoinExchange::printValue(std::string line) {
	std::string 		key, value;
	// double				nbBtc;
	std::stringstream	str;

	key.insert(0, line, 0, line.find("|"));
	value.insert(0, line, line.find("|") + 1);

	trimSpace(key);
	trimSpace(value);

	std::map<std::string, double>::iterator it = this->db.find(key);
	if (it == this->db.end())
		std::cout << "not existing\n";
	// std::cout << "db: " << this->db[key] * atof(value.c_str()) << '\n';
}