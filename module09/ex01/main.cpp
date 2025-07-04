#include "RPN.hpp"

int main(int argc, char **argv) {
	RPN exp;

	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expr>\n";
		return 1;
	}
	exp.printResult(argv[1]);
}