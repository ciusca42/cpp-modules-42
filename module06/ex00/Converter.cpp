#include "Converter.hpp"
#include "colors.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <sstream>

void checkChar(int c) {
	std::cout << "Char: ";
	if (!isascii(c)) 
		std::cout << "Impossible\n";
	else if (!isprint(c))
		std::cout << "Not displayable\n";
	else
		std::cout << static_cast<char>(c) << '\n';
}

int countPrecision(std::string &value) {
	int count = 0;
	int start = value.find(".");

	for (int i = start; i < value.length(); i++) {
		count++;
	}
	return count - 1;
}

int isChar(std::string &value) {
	char c;

	if (isalpha(value[0]) && value.length() == 1) {
		c = value[0];
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		//std::cout << "Char: ";
		checkChar(c);
		std::cout << "Int: " << static_cast<int>(c) << '\n';
		std::cout << "Double: " << static_cast<double>(c) << '\n';
		std::cout << "Float: " << static_cast<float>(c) << "f\n";
		return 1;
	}
	return 0;
}

int isInt(std::string &value) {
	int i;
	std::ostringstream str;
	std::string final;

	i = atoi(value.c_str());
	str << i; 
	final = str.str();
	if (value[0] == '+') {
		value.erase(0, 1);
	}
	if (final == value) {
		i = atoi(value.c_str());
		std::cout << std::fixed << std::setprecision(2);
		checkChar((i));
		std::cout << "Int: ";
		std::cout << i << "\n";
		std::cout << "Double: " << static_cast<double>(i) << '\n';
		std::cout << "Float: " << static_cast<float>(i) << "f\n";
		return 1;
	}
	return 0;
}

int isDouble(std::string &value) {
	double d;
	std::ostringstream str;
	std::string final;

	
	std::cout << std::fixed;
	std::cout << std::setprecision(countPrecision(value));
	d = atof(value.c_str());
	// std::cout << "actual = " << d << '\n';
	str << std::fixed << std::setprecision(countPrecision(value));
	final = str.str();
	if (value[0] == '+') {
		value.erase(0, 1);
	}
	if (final == value) {
		std::cout << "double\n";
		if (d == INFINITY || d == -INFINITY || d != d) {
			std::cout << "Char: Impossible\n";
			std::cout << "Int: Impossible\n";
		}
		else {

			checkChar(static_cast<char>(d));
			std::cout << "Int: " << static_cast<int>(d) << '\n';
		}
		std::cout << "Double: " << d << '\n';
		std::cout << "Float: " << static_cast<float>(d) << "f\n";
		return 1;
	}
	return 0;
}

int isFloat(std::string &value) {
	float f;
	std::ostringstream str;
	std::string final;

	std::cout << std::fixed;
	std::cout << std::setprecision(countPrecision(value));
	f = atof(value.c_str());
	//std::cout << "f = " << f << '\n';
	str << f; 
	final = str.str();
	if (value[0] == '+') {
		value.erase(0, 1);
	}
	if (value[value.length() -1] == 'f')
		value.erase(value.length() -1);
	if (final == value) {
		if (f == INFINITY || f == -INFINITY || f != f) {
			std::cout << "Char: Impossible\n";
			std::cout << "Int: Impossible\n";
		}
		else {

			checkChar(static_cast<char>(f));
			std::cout << "Int: " << static_cast<int>(f) << '\n';
		}
		std::cout << "Double: " << f << '\n';
		std::cout << "Float: " << static_cast<float>(f) << "f\n";
		return 1;
	}
	return 0;
}

ScalarConverter::ScalarConverter(void) {
	if (DEBUG)
		std::cout << LIME400 << "[CONSTRUCTOR]" RESET << "called\n";
}

ScalarConverter::~ScalarConverter(void) {
	if (DEBUG)
		std::cout << LIME400 << "[DESTRUCTOR]" RESET << "called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	*this = obj;
}

void ScalarConverter::convert(std::string value) {
	if (isInt(value))
		return ;
	if (isChar(value))
		return ;
	if (isDouble(value))
		return ;
	if (isFloat(value))
		return ;
	
	std::cerr << ROSE300 << "\n   Error: invalid input\n\n";
	std::cerr << STONE300 << "   Input has invalid characters or it's to big for the for the inserted type\n";
	std::cerr << "   E.G. largest int is: ["<< LIME300 << INT_MAX << RESET << "]\n\n";
	std::cerr << YELLOW300 << "   The only accectable values are: " CYAN300 << "char / int / double / float\n";
	std::cerr << RESET << "   ===========================================================\n";
	std::cerr << YELLOW300 << "   Exception handled: \t\t  " << CYAN300 << " nan / +inf / -inf\n\n" << RESET;
}
