#include "Span.hpp"
#include <exception>
#include <iostream>

int main()
{
	Span test = Span(5);
	Span big = Span(10000);

	test.addNumber(6);
	test.addNumber(3);
	test.addNumber(17);
	test.addNumber(9);
	test.addNumber(11);

	test.print();

	std::cout << '\n';

	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	std::cout << '\n';

	big.addRange(1, 10001);
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	try {
		big.addNumber(3);
	} catch (const std::exception &ex) {
		ex.what();
	}

	return 0;
}