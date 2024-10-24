#include "../classes/PmergeMe.hpp"

PmergeMe::PmergeMe(): vec(0), deq(0), struggler(-1) {}

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

void PmergeMe::setArr(const int *arr, const int N) {
	this->arr = arr;
	this->len = N;

	if (this->len % 2 == 0) {
		struggler = -1;
	}
	else {
		struggler = arr[this->len - 1];
		len--;
	}
}


