#include "../includes/Replace.hpp"


int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << LIME200 "Usage: <filename> set1 set2" RESET << '\n';
		return 1;
	}

	Replace file;
	if (!file.findAndReplace(argv[1], argv[2], argv[3]))
		return 1;
}