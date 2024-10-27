#include "classes/PmergeMe.hpp"
#include "colors.hpp"
#include <bits/types/struct_timeval.h>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unistd.h> 
#include <sys/time.h>

void error(std::string msg, std::string elem) {
	std::cerr << ROSE300 << "Error: " << RESET;
	std::cerr << EMERALD300 << msg << " ";
	std::cerr << LIME300 << elem << '\n';
}

int *parseInput(int argc, char **argv, size_t *N) {
	int 	*arr;
	// int		num;

	// for (int i = 1; i < argc; i++) {
	// 	num = atoi(argv[i]);
	// 	if (num == 0 && argv[i][0] != '0') {
	// 		error("Invalid Number", argv[i]);
	// 		return 0;
	// 	}
	// 	if (num < 0) { 
	// 		error("Invalid Number", argv[i]);
	// 		return 0;
	// 	}
	// }
	// for (int i = 1; i < argc; i++) {
	// 	for (int j = 1; j < argc; j++) {
	// 		// std::cout << j << '\n';
	// 		if (!(strcmp(argv[i], argv[j])) && i != j) {
	// 			error("No duplicated allowed", argv[j]);
	// 			return 0;
	// 		}
	// 	}
	// }
	*N = argc - 1;
	arr = new int[*N];
	for (size_t i = 0; i < *N; i++) {
		arr[i] = atoi(argv[i + 1]);
	}
	return arr;
}

int main(int argc, char **argv) {
    PmergeMe mergeMe;
    int *arr;
    size_t N;
    struct timeval tp_start, tp_end;
    long  us_vector, us_deque;

    if (argc == 1) {
        std::cout << CYAN300 << "\nUsage:" << PINK200 << "./PmergeMe < n1 > < n2 > ...\n" << RESET;
        return 0;
    }

    arr = parseInput(argc, argv, &N);
    mergeMe.setArr(arr, N);

    // Measure sortVector
    gettimeofday(&tp_start, 0);
    mergeMe.sortVector();
    gettimeofday(&tp_end, 0);

    // ms_vector = (tp_end.tv_sec - tp_start.tv_sec) * 1000 +
    //             (tp_end.tv_usec - tp_start.tv_usec) / 1000;
    us_vector = (tp_end.tv_sec - tp_start.tv_sec) * 1000000 +
                (tp_end.tv_usec - tp_start.tv_usec);

    // Measure sortDeque
    gettimeofday(&tp_start, 0);
    mergeMe.sortDeque();
    gettimeofday(&tp_end, 0);

    // ms_deque = (tp_end.tv_sec - tp_start.tv_sec) * 1000 +
    //            (tp_end.tv_usec - tp_start.tv_usec) / 1000;
    us_deque = (tp_end.tv_sec - tp_start.tv_sec) * 1000000 +
               (tp_end.tv_usec - tp_start.tv_usec);

    // Display times with appropriate units
    // if (ms_vector > 0)
    //     std::cout << "sortVector timestamp: " << ms_vector << " ms\n";
    // else
        std::cout << "sortVector timestamp: " << (double)us_vector / 10000 << " us\n";

    // if (ms_deque > 0)
    //     std::cout << "sortDeque timestamp: " << ms_deque << " ms\n";
    // else
        std::cout << "sortDeque timestamp: " << (double)us_deque / 10000 << " us\n";

    delete[] arr;

    return 0;
}