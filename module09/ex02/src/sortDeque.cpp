#include "../classes/PmergeMe.hpp"
#include <algorithm>



std::deque<int> findJacob(std::deque<int> pend) {
	std::deque<int>	jacob;
	long				j, j2;
	int 				prev = 1, prev2 = 0;

	jacob.push_back(0);
	jacob.push_back(1);
	for (size_t i = 2; i < pend.size() + 3; i++) {
		j = prev;
		j2 =  2 * (prev2);
		jacob.push_back(j + j2);

		for (int i = (j + j2) - 1; i > prev; i--) {
			if (i + 1 == (int)pend.size()) {
				jacob.erase(jacob.begin(), jacob.begin() + 3);
				return jacob;
			}
			jacob.push_back(i);
		}
		prev2 = prev;
		prev = j + j2;
	}
	
	jacob.erase(jacob.begin(), jacob.begin() + 3);

	return jacob;
}


void PmergeMe::deqFinalSort(std::pair<int, int> *pairs) {
	std::deque<int> pend, jacob;
	std::deque<int>::iterator it;
	int				index;

	for (size_t i = 0; i < this->len / 2; i++) {
		deq.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	this->deq.insert(deq.begin(), pend[0]);
	jacob = findJacob(pend);
	
	// this->deq.insert(deq.begin(), pend[0]);
	for (size_t i = 0; i < jacob.size(); i++) {
		index = jacob[i] - 1;
		// std::cout << jacob[i] << '\n';
		if (index >= (long)pend.size())
			continue;
		it = std::lower_bound(this->deq.begin(), this->deq.end() -1, pend[index]);
		this->deq.insert(it, pend[index]);
	}
	if (struggler != -1) {
		it = std::lower_bound(this->deq.begin(), this->deq.end(), struggler);
		this->deq.insert(it, struggler);
	}
}

void PmergeMe::sortDeque() {
	int 				j = 0;
	std::pair<int, int> *pairs;

	// parseArr(int *arr, int N);
	pairs = new std::pair<int, int>[len / 2];
	for (size_t i = 0; i < len / 2; i++) {
		pairs[i].first = arr[j];
		pairs[i].second = arr[j + 1];
		j+=2;
	}

	findBigger(pairs, len / 2);
	mergeSort(pairs, 0, len / 2 -1);	
	deqFinalSort(pairs);
	delete[] pairs;
}