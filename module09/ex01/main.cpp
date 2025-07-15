#include "RPN.hpp"
#include "colors.hpp"
#include <exception>

int main(int argc, char **argv) {
	RPN exp;

	if (argc < 2) {
		std::cerr << CYAN200 << "Usage: " << GREEN200 << "./RPN <expr>\n" RESET;
		return 1;
	}
	try {
		exp.printResult(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << ROSE300 << "\nError: " << AMBER200 << e.what() << RESET << std::endl;
	}
}