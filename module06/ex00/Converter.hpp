#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream> // IWYU pragma: keep
#include "colors.hpp" // IWYU pragma: keep

#ifndef DEBUG
# define DEBUG 0
#endif

class ScalarConverter {
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter & obj);
		static void convert(std::string value);
	private:
		ScalarConverter();
};

#endif