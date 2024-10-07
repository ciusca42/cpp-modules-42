#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange(std::string inputFile) { 
	this->setDb();
	this->setInput(inputFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { 
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	this->db = obj.db;
	return *this;
}


void BitcoinExchange::setDb() { 
	std::ifstream dbFile;
	std::string	line;
	std::string key, value;
	int			splitPos;

	dbFile.open("db/data.csv");
	if (!dbFile.is_open())
		exit(0);
	getline(dbFile, line);
	while (getline(dbFile, line)) {
		splitPos = line.find(",");
		key.insert(0, line, 0, splitPos);
		value.insert(0, line, splitPos + 1);
		db[key] = atof(value.c_str());
		key.clear();
		value.clear();
	}
}

std::string BitcoinExchange::parseDate(std::string &inputDate) {
	(void)inputDate;
	std::string parsedDate;

	return "";
}


void BitcoinExchange::printValue(std::string dateInput) {
	std::string date;
	double result;

	for (iter it = this->db.begin(); it != this->db.end(); it++ ) {
		date = parseDate(dateInput);
		result = this->db[date] * ;
		std::cout << date << "=> " << this->db[date] << " = " << result << '\n';
	}
}