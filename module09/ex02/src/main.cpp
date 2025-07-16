#include "../classes/PmergeMe.hpp"
#include "../colors.hpp"
#include <bits/types/struct_timeval.h>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <unistd.h> 
#include <sys/time.h>

void createLogFile(std::string filename, std::vector<long> arr) {
	std::ofstream out;

	out.open(filename.c_str());

	if (!out.is_open()) {
		std::cout << ROSE300 << "failed to create log file!\n" RESET;
		return ;
	}

	for (size_t i = 0; i < arr.size(); i++) {
		out << arr[i];
		if (i % 10 == 0 && i != 0) 
			out << '\n';
		else
			out << " ";
	}
	out.close();
}

void formatPrint(int *arr, int N, std::vector<long> vec) {
	size_t count = 0;
    size_t     countArr = 0;

    
    std::cout << VIOLET400 << "\nBEFORE -> " RESET;
    for (int i = 0; i < N; i++) {
        if (countArr == 6)
            break;
        std::cout << VIOLET200 << arr[i] << " " RESET;
        countArr++;
    }
    if (countArr < vec.size()) {
		std::cout << "[...] ";
		createLogFile("before.log", vec);
		std::cout << STONE400 << " => log file created '" << LIME300 << "before.log" << STONE300 "'" RESET;
	}
    std::cout << VIOLET400 << "\nAFTER  -> " RESET;
	for (size_t i = 0; i < vec.size(); i++) {
		if (count == 6)
			break;
		std::cout << VIOLET200 << vec[i] << " " RESET;
		count++;
	}
	if (count < vec.size()) {
		std::cout << "[...] ";
		createLogFile("after.log", vec);
		std::cout << STONE400 << " => log file created '" << LIME300 << "after.log" << STONE300 "'" RESET;
	}
	std::cout << '\n';
}

void error(std::string msg, std::string elem) {
	std::cerr << ROSE300 << "Error: " << RESET;
	std::cerr << EMERALD300 << msg << ": " RESET << "'";
	std::cerr << LIME300 << elem << RESET "'" << '\n' << '\n';
}

char firstOcc(std::string str) {

    while (isspace(str[0]))
        str.erase(0);
    return str[0];
}

int *inputError(std::string msg, int *arr, std::string num) {
	error(msg, num);
	delete[] arr;
	return 0;
}

int *parseInput(int argc, char **argv, size_t *N) {
	int 	*arr;
	long	num;

	*N = argc - 1;
	arr = new int[*N];
	for (int i = 1; i < argc; i++) {
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN) {
			return inputError("Number to big => Limits: INT_MAX / INT_MIN" , arr, argv[i]);
		}
		if (num == 0 && argv[i][0] != '0') {
			return inputError("Invalid Number", arr, argv[i]);
		}
        if (num < 0 && firstOcc(argv[i]) != '-') {
			return inputError("Number too big", arr, argv[i]);
        }
		if (num < 0) { 
			return inputError("Only positive numbers allowed", arr, argv[i]);
		}
        arr[i - 1] = num;
	}
	return arr;
}

int main(int argc, char **argv) {
    PmergeMe mergeMe;
    int *arr;
    size_t N;
    struct timeval tp_start, tp_end;
    long long us_vector, us_deque;

    if (argc == 1) {
        std::cout << CYAN300 << "\nUsage:" << PINK200 << "./PmergeMe <n1> <n2> ...\n\n" << RESET;
        return 0;
    }

    arr = parseInput(argc, argv, &N);
    if (!arr) {
		return 0;
	}
	if (N <= 1) {
		std::cout << CYAN300 << "\nUsage:" << PINK200 << "./PmergeMe <n1> <n2> ...\n\n" << RESET;
		return 0;
	}
    mergeMe.setArr(arr, N);

    gettimeofday(&tp_start, 0);
    mergeMe.sortVector();
    gettimeofday(&tp_end, 0);

    us_vector = (tp_end.tv_sec - tp_start.tv_sec) * 1000000 +
                (tp_end.tv_usec - tp_start.tv_usec);

    gettimeofday(&tp_start, 0);
    mergeMe.sortDeque();
    gettimeofday(&tp_end, 0);

    formatPrint(arr, N, mergeMe.getVec());

    us_deque = (tp_end.tv_sec - tp_start.tv_sec) * 1000000 +
               (tp_end.tv_usec - tp_start.tv_usec);


    std::cout << CYAN200 << "Vector" << RESET << " timestamp: " << EMERALD400 << (double)us_vector / 10000 << YELLOW200 << " ms\n" RESET;

    std::cout << AMBER300 << "Deque" << RESET << " timestamp: " << EMERALD400 << (double)us_deque / 10000 << YELLOW200 << " ms\n" RESET;

    delete[] arr;

    std::cout << '\n';

    return 0;
}