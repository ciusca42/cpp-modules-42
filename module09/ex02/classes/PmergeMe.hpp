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
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & obj);
		PmergeMe & operator=(const PmergeMe & obj);

		void initArr(const int *arr, const int n);
		void sortVector();
		void sortDeque();
};

#endif