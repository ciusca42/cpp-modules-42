#include "../classes/PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <utility>
#include <vector>

void PmergeMe::printPairs(std::pair<int, int> *pairs, size_t n) {
	for (size_t i = 0; i < n; i++) {
		std::cout << i << ": ";
		std::cout << YELLOW300 << "first -> " LIME300 << pairs[i].first << " ";
		std::cout << CYAN200 "second -> " LIME300 << pairs[i].second << "\n" RESET;
	}
}

void PmergeMe::findBigger(std::pair<int, int> *pairs, size_t n) {
	int first, second;

	for (size_t i = 0; i < n; i++) {
		first = pairs[i].first;
		second = pairs[i].second;
		if (second > first) {
			pairs[i].first = second;
			pairs[i].second = first;
		}
	}
}

int PmergeMe::isSorted(std::pair<int, int> *pairs, size_t n) {
	for (size_t i = 0; i < n -1; i++) {
		if (!(pairs[i].first < pairs[i + 1].first))
			return 0;
	}
	return 1;
}

void PmergeMe::insertionSort(std::pair<int, int> *pairs, size_t n, int curr) {

		int j;
		int key;
		std::pair<int, int> temp;

		if (isSorted(pairs, n))
			return;
		key = pairs[curr].first;
		j = curr - 1;
		while (j >= 0 && pairs[j].first > key) {
			temp = pairs[j + 1];
			pairs[j + 1] = pairs[j];
			pairs[j] = temp;
			j = j -1;
		}
		pairs[j + 1].first = key;
		insertionSort(pairs, n, ++curr);
}


std::vector<long> jacobIndex(std::vector<long> pend) {
	std::vector<long>	jacob;
	long				j, j2;
	long				prev = 1;

	jacob.push_back(0);
	jacob.push_back(1);
	for (size_t i = 2; i < pend.size() + 1; i++) {
		j = jacob[i -1];
		j2 =  2 * (jacob[i - 2]);
		jacob.push_back(j + j2);
		for (int i = (j + j2) - 1; i > prev; i--) {
			jacob.push_back(i);
		}
		prev = j + j2;
	}
	jacob.erase(jacob.begin(), jacob.begin() + 3);
	return jacob;
}

void printPendMain(std::vector<long> main, std::vector<long> pend) {
	std::cout << "----- [MAIN] -----\n";
	for (size_t i = 0; i < main.size(); i++) {
		std::cout << main[i] << " ";
	}
	std::cout << '\n';
	std::cout << "----- [PEND] -----\n";
	for (size_t i = 0; i < pend.size(); i++) {
		std::cout << pend[i] << " ";
	}
	std::cout << '\n';
}

void PmergeMe::vecFinalSort(std::pair<int, int> *pairs, int struggler) {
	std::vector<long> pend, jacob;
	std::vector<long>::iterator it;
	(void)struggler;
	int				index;

	for (size_t i = 0; i < this->len / 2; i++) {
		vec.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	vec.insert(vec.begin(), pend[0]);
	jacob = jacobIndex(pend);
	for (size_t i = 0; i < jacob.size(); i++) {
		index = jacob[i] - 1;
		// std::cout << jacob[i] << '\n';
		if (index >= (long)jacob.size())
			continue;
		it = std::lower_bound(this->vec.begin(), this->vec.end(), pend[index]  - 1);
		this->vec.insert(it, pend[index]);
	}
	if (struggler != -1) {
		it = std::lower_bound(this->vec.begin(), this->vec.end(), struggler);
		this->vec.insert(it, struggler);
	}
	for (size_t i = 0; i < this->vec.size(); i++) {
		std::cout << this->vec[i] << " ";
	}
	std::cout << '\n';
}

void PmergeMe::sortVector(int *arr , int N) {
	int					struggler;
	int 				j = 0;
	std::pair<int, int> *pairs;

	// parseArr(int *arr, int N);
	this->len = N;
	if (this->len % 2 == 0) {
		struggler = -1;
	}
	else {
		struggler = arr[this->len - 1];
		len--;
	}
	pairs = new std::pair<int, int>[len / 2];
	for (size_t i = 0; i < len / 2; i++) {
		pairs[i].first = arr[j];
		pairs[i].second = arr[j + 1];
		j+=2;
	}

	findBigger(pairs, len / 2);
	insertionSort(pairs, len / 2, 1);	
	vecFinalSort(pairs, struggler);

	delete[] pairs;
}