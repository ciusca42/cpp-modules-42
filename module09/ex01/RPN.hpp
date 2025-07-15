#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <cstddef> // IWYU pragma: keep
#include "colors.hpp" // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep
#include <cstdlib>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN & obj);
		RPN & operator=(const RPN & obj);

		void printResult(std::string expr);
	private:
		//container
		std::stack<std::string> exp;
		std::stack<std::string> result;

		void performOp(std::stack<std::string> &result);
		int parseExpr(std::stack<std::string> exp);
		int tokenizer(std::string exprStr);
		int isSign(std::string elem);
		int checkValid(std::string str, int i);
		void err(const std::string msg);
		void printStack(std::stack<std::string> &stack);
};

#endif