#include "RPN.hpp"
#include "colors.hpp"
#include <exception>

std::string normalizeInput(int argc, char **argv) {
	std::string normalized;

	for (int i = 1; i < argc; i++) {
		normalized.append(argv[i]);
		if (i != argc -1)
			normalized.append(" ");
	}
	
	return normalized;
}

int main(int argc, char **argv) {
	RPN exp;
	std::string input;

	if (argc < 2) {
		std::cerr << CYAN200 << "Usage: " << GREEN200 << "./RPN <expr>\n" RESET;
		return 1;
	}

	if (argc > 2)
		input = normalizeInput(argc, argv);
	else
		input = argv[1];
	try {
		exp.printResult(input);
	} catch (const std::exception &e) {
		std::cerr << ROSE300 << "\nError: " << AMBER200 << e.what() << RESET << std::endl;
	}
}