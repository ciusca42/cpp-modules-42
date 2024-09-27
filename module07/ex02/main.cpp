#include "Array.hpp"
#include <exception>
#include <iostream>

int main() {
    Array<int> arr(4); // Create an Array of 3 integers
	for (int i = 0; i < (int)arr.size(); i++) {
		arr[i] = i + 1;
	}
	
	Array<int> temp = arr;
	
	for (int i = 0; i < (int)arr.size(); i++) {
		std::cout << "arr1: " << arr[i] << " ---- ";
		std::cout << "arr2: " << temp[i] << '\n';
	}
	try {
		arr[10];
	} catch (const std::exception &exp) {
		std::cout << "Error: " << exp.what();
	}
    return 0;
}
