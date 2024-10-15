#include "RPN.hpp"
#include "colors.hpp"
#include <climits>
#include <iostream>

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

int RPN::isSign(int c) {
	return (c == '-' || c == '+' || c == '/' || c == '*');
}

void RPN::printStack()
{
    int x;
    
	if (this->exp.empty()) 
        return;     
 
	x = this->exp.top();
    this->exp.pop();
    printStack();
	std::cout << (x) << "\n";
    this->exp.push(x);
}

int RPN::checkValid(std::string str, int i) {
	if (i == 0)
		return 1;
	return isspace(str[i - 1]);
}

int RPN::tokenizer(std::string exprStr) {
	for (int i = exprStr.length() - 1; i >= 0; i--) {
		if (isspace(exprStr[i]))
			continue;

		if (isdigit(exprStr[i]) && checkValid(exprStr, i)) {
			exp.push(exprStr[i] - '0');
		}
		else if (isSign(exprStr[i]) && checkValid(exprStr, i )) {
			exp.push((exprStr[i]));
		}
		else {
			err("invalid token");
			return 0;
		}
	}
	return 1;
}

int RPN::performOp(int first, int second, char sign) {
	long result;

	if (isSign(first) || isSign(second)) {
		err("invalid syntax expression");
		exit(1);
	}
	switch (sign) {
		case '+':
			result =  first + second;
			break;
		case '-':
			result =  first - second;
			break;
		case '*':
			result =  first * second;
			break;
		case '/':
			if (second == 0) {
				std::cerr << ROSE300 << "\nError: " << AMBER200 << "cannot divide by 0\n\n" RESET;
				exit(1);
			}
			result =  first / second;
			break;
	}
	if (result > INT_MAX || result < INT_MIN) {
		err("number too big/low");
		exit(1);
	}
	return result;
}

void RPN::printResult(std::string expr) {
	// int first, second;
	char sign;
	int first, second;

	if (!tokenizer(expr))
		return ;
	while (this->exp.size() > 2) {
		first = this->exp.top();
		this->exp.pop();
		second = this->exp.top();
		this->exp.pop();
		sign = static_cast<char>(exp.top());
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