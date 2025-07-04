#include "easyfind.hpp"
#include <vector>

int main(void) { 
	const int temp[] = {2, 3, 1, 6, 4, 43, 23};
	std::vector<int> arr(temp, temp + sizeof(temp) / sizeof(temp[0]) );

	std::vector<int>::iterator result = easyfind(arr, 23);
	if (result != arr.end()) {
		std::cout << "Element found: " << *result << std::endl;
	} else {
		std::cout << "Element not found" << std::endl;
	}

	std::vector<int> arr2;

	result = easyfind(arr2, 23);
	if (result != arr2.end()) {
		std::cout << "Element2 found: " << *result << std::endl;
	} else {
		std::cout << "Element2 not found" << std::endl;
	}

	return 0;



}
