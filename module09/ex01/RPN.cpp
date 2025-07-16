#include "RPN.hpp"
#include "colors.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>


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

void RPN::printStack(std::stack<std::string> &stack) {
	std::stack<std::string> tempStack = stack;
	std::cout << "Stack contents: ";
	while (!tempStack.empty()) {
		std::cout << tempStack.top() << " ";
		tempStack.pop();
	}
	std::cout << std::endl;
}

// void RPN::printStack() {
//     std::string x;
    
// 	if (this->exp.empty()) 
//         return;     
 
// 	x = this->exp.top();
//     this->exp.pop();
//     printStack();
// 	std::cout << (x) << "\n";
//     this->exp.push(x);
// }

int RPN::checkValid(std::string str, int i) {
	// std::cout << "str to validate: " << str << " index: " << i << std::endl;
	if (i == 0)
		return 1;
	if (isspace(str[i -1]))
		return 1;
	return 0;
	// return isspace(str[i - 1]);
}

int RPN::tokenizer(std::string exprStr) {
	std::string toPush;

	if (exprStr.empty()) {
		return 0;
	}
	for (int i = exprStr.length() - 1; i >= 0; i--) {
		toPush.clear();
		if (isspace(exprStr[i]))
			continue;
		if (checkValid(exprStr, i) == 1) {
			toPush.push_back(exprStr[i]);
			this->exp.push(toPush);
		}
		else {
			throw std::runtime_error("invalid expression");
			return 0;
		}
	}
	if (this->exp.empty())
		throw std::runtime_error("empty input");
	return 1;
}

// int RPN::parseExpr(std::stack<int> expr) {

// }

void RPN::performOp(std::stack<std::string> &result) {
	long operation;
	long num1, num2;
	std::ostringstream resultStr;
	char sign;

	sign = result.top().c_str()[0];
	// std::cout << "sign: " << sign << std::endl;
	result.pop();
	num2 = std::atol(result.top().c_str());
	if (num1 == 0 && result.top() != "0") {
		throw std::runtime_error("invalid syntax expression");
	}
	result.pop();
	num1 = std::atol(result.top().c_str());
	if (num2 == 0 && result.top() != "0") {
		throw std::runtime_error("invalid syntax expression");
	}
	result.pop();
	// std::cout << "first: " << num1 << " sign: " << sign << " second: " << num2 << std::endl;
	switch (sign) {
		case '+':
			operation =  num1 + num2;
			break;
		case '-':
			operation =  num1 - num2;
			break;
		case '*':
			operation =  num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				throw std::runtime_error("cannot divide by 0");
			}
			operation =  num1 / num2;
			break;
		default:
			throw std::runtime_error("invalid sign");

	}
	if (operation > INT_MAX || operation < INT_MIN) {
		throw std::runtime_error("number too big/low");
	}
	// exit(1);
	resultStr << operation;
	// std::cout << "resultstr: " << resultStr.str() << std::endl;
	result.push(resultStr.str());
}

void RPN::printResult(std::string expr) {
	// int first, second;
	std::string elem;

	if (!tokenizer(expr))
		return ;
	// printStack();
	// std::cout << "size: " << this->exp.size() << std::endl; 
	if (this->exp.size() == 2) {
		throw std::runtime_error("invalid expression\n");
		return ;
	}
	while (this->exp.size() > 0) {
		// std::cout << "hello\n";
		elem = this->exp.top();
		
		this->exp.pop();
		result.push(elem);
		// std::cout << "pushing: " << elem << std::endl;
		if (isSign(elem)) {
			// printStack(result);
			// std::cout << "performing operation: " << std::endl;
			performOp(result);
		}
		elem.clear();
		// second = this->exp.top();
		// this->exp.pop();
		// third = this->exp.top();
		// this->exp.pop();
		// this->exp.push(performOp(first,second, third));
	}
	printStack(result);
	if (result.size() != 1) {
		throw std::runtime_error("invalid expression");
		return ;
	}
	/*
	*
	* if result is not 1, error();
	*
	*/
	std::cout << GREEN200 << "Result: " << RESET;
	std::cout << this->result.top() << '\n';
}