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
		std::deque<int>		deq;

		int					struggler;
		const int			*arr;
		size_t				len;

		
		void vecFinalSort(std::pair<int, int> *pairs);
		void deqFinalSort(std::pair<int, int> *pairs);

		void findBigger(std::pair<int, int> *pairs, size_t n);
		void printPairs(std::pair<int, int> *pairs, size_t n);
		void mergeSort(std::pair<int, int> *pairs, int left, int righ);
		void merge(std::pair<int, int> *pairs, int left, int mid, int right);
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & obj);
		PmergeMe & operator=(const PmergeMe & obj);
		void setArr(const int *arr,const int N);
		void sortVector();
		void sortDeque();
		std::vector<long>	getVec(void) const;
		std::deque<int> 	getDeq(void) const;
};

#endif