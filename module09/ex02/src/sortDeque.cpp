// #include "../classes/PmergeMe.hpp"
// #include <cmath>
// #include <cstdlib>

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

// void PmergeMe::sortDeque(int *arr , int N) {
// 	int					struggler;
// 	int 				j = 0;
// 	std::pair<int, int> *pairs;

// 	// parseArr(int *arr, int N);
// 	this->len = N;
// 	if (this->len % 2 == 0) {
// 		struggler = -1;
// 	}
// 	else {
// 		struggler = arr[this->len - 1];
// 		len--;
// 	}
// 	pairs = new std::pair<int, int>[len / 2];
// 	for (size_t i = 0; i < len / 2; i++) {
// 		pairs[i].first = arr[j];
// 		pairs[i].second = arr[j + 1];
// 		j+=2;
// 	}

// 	findBigger(pairs, len / 2);
// 	insertionSort(pairs, len / 2, 1);	
// 	deqFinalSort(pairs, struggler);

// 	delete[] pairs;
// }