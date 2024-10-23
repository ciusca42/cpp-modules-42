#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iostream> // IWYU pragma: keep
#include <sys/types.h>
#include <algorithm> // IWYU pragma: keep
#include <climits>
#include <cstddef> // IWYU pragma: keep
#include <vector>
class Span {
	public:
		Span(uint N);
		~Span();
		Span(const Span & obj);
		Span & operator=(const Span & obj);
	
		void addNumber(uint n);
		uint shortestSpan();
		uint longestSpan();
		void addRange(uint first, uint last);

		void print();

	private:
		std::vector<int> _arr;
		uint			 _maxSize;
	class NotEnoughNumbers: public std::exception {
		const char *what() const throw();
	};
};

#endif