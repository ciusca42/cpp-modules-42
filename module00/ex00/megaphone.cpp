#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			argv[i][j] = toupper(argv[i][j]);
		}
		std::cout << argv[i] << ' ';
	}
	std::cout << '\n';
	return 0;
}
