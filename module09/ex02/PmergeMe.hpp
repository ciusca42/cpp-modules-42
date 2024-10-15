#ifndef PMERGEME_HPP
# define PMERGEME_HPP



class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & obj);
		PmergeMe & operator=(const PmergeMe & obj);
};

#endif