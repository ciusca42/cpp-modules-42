#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << ORANGE300 << "Usage: " CYAN300 << "./scalar < ARG >\n" RESET;
		return 0;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
