#include "RPN.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>


RPN::RPN(std::string expr): _exprStr(expr) {
	this->tokenizer();
};

RPN::~RPN() {};

RPN::RPN(const RPN &obj) {
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj) {
	if (this == &obj)
		return *this;
	this->exp = obj.exp;
	this->_exprStr = obj._exprStr;
	return *this;
}

void RPN::err(const std::string msg) {
	std::cerr << ROSE300 << "\nError: " << RESET;
	std::cerr << AMBER200 << msg << '\n' << RESET << "\n";
}

char RPN::isSign(int c) {
	return (c == '-' || c == '+' || c == '/' || c == '*');
}

void PrintStack(std::stack<char> s)
{
    int x;
    
	if (s.empty()) 
        return;     
 
	x = s.top();
    s.pop();
    PrintStack(s);
	std::cout << static_cast<char>(x) << "\n";
    s.push(x);
}

void RPN::tokenizer() {
	for (size_t i = 0; i < _exprStr.length(); i++) {
		if (isspace(_exprStr[i]))
			continue;
		if (isdigit(_exprStr[i]))
			exp.push(_exprStr[i]);
		else if (isSign(_exprStr[i]))
			exp.push((_exprStr[i]));
		else {
			err("invalid token");
			exit(0);
		}
	}
}

void RPN::printResult() {
	PrintStack(this->exp);
}