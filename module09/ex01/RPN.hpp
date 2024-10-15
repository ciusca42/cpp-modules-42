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
		std::stack<int> exp;

		int performOp(int first, int second, char sign);

		int tokenizer(std::string exprStr);
		int isSign(int c);
		int checkValid(std::string str, int i);
		void err(const std::string msg);
		void printStack();
};

#endif