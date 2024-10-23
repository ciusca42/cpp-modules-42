#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# ifndef DEBUG
	#define DEBUG 0
# endif

#include "../colors.hpp" // IWYU pragma: keep
#include <cstddef>
#include <deque>
#include <vector>
#include <iostream> // IWYU pragma: keep

class PmergeMe {
	private:
		std::vector<long>	vec;
		std::deque<long>	deq;
		size_t				len;

		
		void vecFinalSort(std::pair<int, int> *pairs, int struggler);
		void deqFinalSort(std::pair<int, int> *pairs, int struggler);

		int isSorted(std::pair<int, int> *pairs, size_t n);
		void findBigger(std::pair<int, int> *pairs, size_t n);
		void printPairs(std::pair<int, int> *pairs, size_t n);
		void insertionSort(std::pair<int, int> *pairs, size_t n, int curr);
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & obj);
		PmergeMe & operator=(const PmergeMe & obj);

		void sortVector(int *arr, int N);
		void sortDeque(int *arr, int N);
};

#endif