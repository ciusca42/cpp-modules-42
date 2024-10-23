#include "../classes/PmergeMe.hpp"

PmergeMe::PmergeMe(): vec(0), deq(0) {}

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &obj) {
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	if (this == &obj)
		return *this;
	this->vec = obj.vec;
	this->deq = obj.deq;
	return *this;
}



