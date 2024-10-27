#include "../classes/PmergeMe.hpp"

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


void PmergeMe::merge(std::pair<int, int> *pairs, int left, int mid, int right) {

	int len = mid - left + 1;
	int len2 = right - mid;
	std::pair<int, int> L[len], R[len2];
	int i = 0, j = 0;
	int k = left;

	// printPairs(pairs, this->len / 2);
	for (int i = 0; i < len; i++) {
		L[i] = pairs[left + i];
	}
	for (int i = 0; i < len2; i++) {
		R[i] = pairs[mid + 1 + i];
	}

	while (i < len && j < len2) {
		if (L[i].first <= R[j].first) {
			pairs[k] = L[i];
			i++;
		}
		else {
			pairs[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < len) {
		pairs[k] = L[i];
		i++;
		k++;
	}
	while (j < len2) {
		pairs[k] = R[j];
		j++;
		k++;
	}

}

void PmergeMe::mergeSort(std::pair<int, int> *pairs, int left, int right) {
	int mid;

	if (left >= right)
		return;
	mid =  left + (right - left) / 2;
	mergeSort(pairs, left, mid);
	mergeSort(pairs, mid + 1, right);
	merge(pairs, left, mid, right);
}


std::vector<long> jacobIndex(std::vector<long> pend) {
	std::vector<long>	jacob;
	long				j, j2;
	int 				prev = 1, prev2 = 0;

	jacob.push_back(0);
	jacob.push_back(1);
	for (size_t i = 2; i < pend.size() + 1; i++) {
		j = prev;
		j2 =  2 * (prev2);
		jacob.push_back(j + j2);

		for (size_t i = (j + j2) - 1; i > (size_t)prev; i--) {
			if (i + 1 == pend.size()) {
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

void PmergeMe::vecFinalSort(std::pair<int, int> *pairs) {
	std::vector<long> pend, jacob;
	std::vector<long>::iterator it;

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
		if (index >= (long)pend.size())
			continue;
		it = std::lower_bound(this->vec.begin(), this->vec.end(), pend[index]  - 1);
		this->vec.insert(it, pend[index]);
	}
	if (struggler != -1) {
		it = std::lower_bound(this->vec.begin(), this->vec.end(), struggler);
		this->vec.insert(it, struggler);
	}

}

void formatPrint(std::vector<long> vec) {
	int count = 0;
	for (size_t i = 0; i < vec.size(); i++) {
		if (count == 4)
			break;
		std::cout << vec[i] << " ";
		count++;
	}
	std::cout << '\n';
}

void PmergeMe::sortVector() {
	int 				j = 0;
	std::pair<int, int> *pairs;

	pairs = new std::pair<int, int>[len / 2];
	for (size_t i = 0; i < len / 2; i++) {
		pairs[i].first = arr[j];
		pairs[i].second = arr[j + 1];
		j+=2;
	}

	findBigger(pairs, len / 2);
	// printPairs(pairs, len /2);
	mergeSort(pairs, 0, len / 2 -1);	
	// printPairs(pairs, len /2);
	vecFinalSort(pairs);
	formatPrint(vec);
	delete[] pairs;
}