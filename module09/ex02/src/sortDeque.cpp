#include "../classes/PmergeMe.hpp"
#include <algorithm>

// std::deque<long> jacobIndex(std::deque<long> pend) {
// 	std::deque<long>	jacob;
// 	long				j, j2;
// 	long				prev = 1;

// 	jacob.push_back(0);
// 	jacob.push_back(1);
// 	for (size_t i = 2; i < pend.size() + 1; i++) {
// 		j = jacob[i -1];
// 		j2 =  2 * (jacob[i - 2]);
// 		jacob.push_back(j + j2);
// 		for (int i = (j + j2) - 1; i > prev; i--) {
// 			jacob.push_back(i);
// 		}
// 		prev = j + j2;
// 	}
// 	jacob.erase(jacob.begin(), jacob.begin() + 3);
// 	return jacob;
// }7,8,27,100,11,46,2,53};
	
// 	std::vector<long>::iterator it;
// 	(void)struggler;
// 	int				index;

// 	for (size_t i = 0; i < this->len / 2; i++) {
// 		vec.push_back(pairs[i].first);
// 		pend.push_back(pairs[i].second);
// 	}
	
// 	vec.insert(vec.begin(), pend[0]);
// 	// jacob = jacobIndex(pend);
// 	for (size_t i = 0; i < jacob.size(); i++) {
// 		index = jacob[i] - 1;
// 		// std::cout << jacob[i] << '\n';
// 		if (index >= (long)jacob.size())
// 			continue;
// 		it = std::lower_bound(this->vec.begin(), this->vec.end(), pend[index]  - 1);
// 		this->vec.insert(it, pend[index]);
// 	}
// 	if (struggler != -1) {
// 		it = std::lower_bound(this->vec.begin(), this->vec.end(), struggler);
// 		this->vec.insert(it, struggler);
// 	}
// 	for (size_t i = 0; i < this->vec.size(); i++) {
// 		std::cout << this->vec[i] << " ";
// 	}
// 	std::cout << '\n';
// }

void formatPrint(std::deque<int> vec) {
	int count = 0;
	for (size_t i = 0; i < vec.size(); i++) {
		if (count == 4)
			break;
		std::cout << vec[i] << " ";
		count++;
	}
	std::cout << '\n';
}

std::deque<int> findJacob(std::deque<int> pend) {
	std::deque<int>	jacob;
	long				j, j2;
	int 				prev = 1, prev2 = 0;

	jacob.push_back(0);
	jacob.push_back(1);
	for (size_t i = 2; i < pend.size() + 1; i++) {
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
	// std::cout << "--- jacob --- \n";
	// for (size_t i = 0; i < jacob.size(); i++) {
	// 	std::cout << jacob[i] << " ";
	// }
	// std::cout << '\n';
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
	// for (size_t i = 0; i < this->vec.size(); i++) {
	// 	std::cout << this->deq[i] << " ";
	// }
	// std::cout << '\n';
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
	formatPrint(deq);
	delete[] pairs;
}