#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <cstddef> // IWYU pragma: keep
#include "colors.hpp" // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep

class RPN {
	public:
		RPN(std::string expr);
		~RPN();
		RPN(const RPN & obj);
		RPN & operator=(const RPN & obj);

		void printResult();
	private:
		//container
		std::stack<char> exp;
		std::string		_exprStr;
		void tokenizer();
		char isSign(int c);
		void err(const std::string msg);
};

#endif