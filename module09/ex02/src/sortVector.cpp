#include "../classes/PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <utility>

void printPairs(std::pair<int, int> *pairs, size_t n) {
	for (size_t i = 0; i < n; i++) {
		std::cout << i << ": ";
		std::cout << YELLOW300 << "first -> " LIME300 << pairs[i].first << " ";
		std::cout << CYAN200 "second -> " LIME300 << pairs[i].second << "\n" RESET;
	}
}

void findBigger(std::pair<int, int> *pairs, size_t n) {
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

int isSorted(std::pair<int, int> *pairs, size_t n) {
	for (size_t i = 0; i < n -1; i++) {
		if (!(pairs[i].first < pairs[i + 1].first))
			return 0;
	}
	return 1;
}

void insertionSort(std::pair<int, int> *pairs, size_t n, int curr) {

		int j;
		int key;

		key = pairs[curr].first;
		j = curr - 1;
		if (isSorted(pairs, n))
			return;
		while (j >= 0 && pairs[j].first > key) {
			pairs[j + 1].first = pairs[j].first;
			j = j -1;
		}
		pairs[j + 1].first = key;
		insertionSort(pairs, n, ++curr);
}

void PmergeMe::sortVector() {
	int					struggler;
	int 				j = 0;
	std::pair<int, int> *pairs;

	if (this->len % 2 == 0) {
		struggler = -1;
	}
	else {
		struggler = this->vec[len - 1];
		this->vec.erase(vec.end() - 1);
		len--;
	}
	pairs = new std::pair<int, int>[len / 2];
	for (size_t i = 0; i < len / 2; i++) {
		pairs[i].first = this->vec[j];
		pairs[i].second = this->vec[j + 1];
		j+=2;
	}

	printPairs(pairs, len / 2);

	findBigger(pairs, len / 2);
	insertionSort(pairs, len / 2, 1);
	std::cout << "\n----sorted-----\n";
	printPairs(pairs, len / 2);
}