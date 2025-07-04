#include "RPN.hpp"
#include "colors.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>


RPN::RPN() {};

RPN::~RPN() {};

RPN::RPN(const RPN &obj) {
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj) {
	if (this == &obj)
		return *this;
	this->exp = obj.exp;
	return *this;
}

void RPN::err(const std::string msg) {
	std::cerr << ROSE300 << "\nError: " << RESET;
	std::cerr << AMBER200 << msg << '\n' << RESET << "\n";
}

int RPN::isSign(std::string elem) {
	// std::cout << "isSign: " << elem << std::endl;
	if (elem.length() > 1)
		return 0;
	return (elem[0] == '-' || elem[0] == '+' || elem[0] == '/' || elem[0] == '*');
}

void RPN::printStack()
{
    std::string x;
    
	if (this->exp.empty()) 
        return;     
 
	x = this->exp.top();
    this->exp.pop();
    printStack();
	std::cout << (x) << "\n";
    this->exp.push(x);
}

int RPN::checkValid(std::string str, int i) {
	std::cout << "str to validate: " << str << " index: " << i << std::endl;
	if (i == 0)
		return 1;
	if (isspace(str[i -1]))
		return 1;
	return 0;
	// return isspace(str[i - 1]);
}

int RPN::tokenizer(std::string exprStr) {
	std::string toPush;

	for (int i = exprStr.length() - 1; i >= 0; i--) {
		toPush.clear();
		if (isspace(exprStr[i]))
			continue;
		if (checkValid(exprStr, i) == 1) {
			toPush.push_back(exprStr[i]);
			this->exp.push(toPush);
		}
		else {
			err("invalid token");
			return 0;
		}
	}
	return 1;
}

// int RPN::parseExpr(std::stack<int> expr) {

// }

std::string RPN::performOp(std::string first, std::string second, std::string sign) {
	long result;
	long num1, num2;
	std::ostringstream resultStr;

	// std::cout << "first: " << first << " sign: " << sign << " second: " << second << std::endl;
	num1 = std::atol(first.c_str());
	num2 = std::atol(second.c_str());
	
	if (isSign(first) || isSign(second)) {
		err("invalid syntax expression");
		exit(1);
	}
	switch (sign[0]) {
		case '+':
			result =  num1 + num2;
			break;
		case '-':
			result =  num1 - num2;
			break;
		case '*':
			result =  num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				std::cerr << ROSE300 << "\nError: " << AMBER200 << "cannot divide by 0\n\n" RESET;
				exit(1);
			}
			result =  num1 / num2;
			break;
	}
	if (result > INT_MAX || result < INT_MIN) {
		err("number too big/low");
		exit(1);
	}
	resultStr << result;
	// std::cout << "resultstr: " << resultStr.str() << std::endl;
	return resultStr.str();
}

void RPN::printResult(std::string expr) {
	// int first, second;
	std::string sign;
	std::string first, second;

	if (!tokenizer(expr))
		return ;
	printStack();
	// std::cout << "size: " << this->exp.size() << std::endl; 
	while (this->exp.size() > 2) {
		// std::cout << "hello\n";
		first = this->exp.top();
		this->exp.pop();
		second = this->exp.top();
		this->exp.pop();
		sign = this->exp.top();
		this->exp.pop();
		this->exp.push(performOp(first, second, sign));
	}
	if (this->exp.size() == 2) {
		err("invalid syntax expression");
		return ;
	}
	std::cout << GREEN200 << "Result: " << RESET;
	std::cout << this->exp.top() << '\n';
}