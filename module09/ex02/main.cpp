#include "classes/PmergeMe.hpp"
#include "colors.hpp"
#include <bits/types/struct_timeval.h>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>


void error(std::string msg, std::string elem) {
	std::cerr << ROSE300 << "Error: " << RESET;
	std::cerr << EMERALD300 << msg << " ";
	std::cerr << LIME300 << elem << '\n';
}

int *parseInput(int argc, char **argv, size_t *N) {
	int 	*arr;
	int		num;

	for (int i = 1; i < argc; i++) {
		num = atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0') {
			error("Invalid Number", argv[i]);
			return 0;
		}
		if (num < 0) { 
			error("Invalid Number", argv[i]);
			return 0;
		}
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 1; j < argc; j++) {
			// std::cout << j << '\n';
			if (!(strcmp(argv[i], argv[j])) && i != j) {
				error("No duplicated allowed", argv[j]);
				return 0;
			}
		}
	}
	*N = argc - 1;
	arr = new int[*N];
	for (size_t i = 0; i < *N; i++) {
		arr[i] = atoi(argv[i + 1]);
	}
	return arr;
}

int main(int argc, char **argv) {
	PmergeMe		mergeMe;
	int				*arr;
	size_t			N;
	struct timeval	tp, tp2;
	long int		ms;

	if (argc == 1) {
		std::cout << CYAN300 << "\nUsage:" << PINK200 << "./PmergeMe < n1 > < n2 > ...\n" << RESET;
		return 0;
	}

	arr = parseInput(argc, argv, &N);

	mergeMe.setArr(arr, N);

	gettimeofday(&tp, 0);
	mergeMe.sortVector();
	gettimeofday(&tp2, 0);
	ms = (tp2.tv_sec * 1000 + tp2.tv_usec / 1000) - (tp.tv_sec * 1000 + tp.tv_usec / 1000);
	std::cout << "timestamp: " << ms << " ms\n";
	mergeMe.sortDeque();

	delete[] arr;

	return 0;

}