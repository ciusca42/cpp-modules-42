#include "iter.hpp"
#include <cctype>


int main(void) { 
	int			arr1[] = {1, 2, 5, 6};
	std::string	arr2[] = {"hello", "this", "is", "array"};
	char		arr3[] = {'c', 'i', 'a', 'o'}; 



	iter(arr1, 4, print);
	std::cout << '\n';
	iter(arr2, 4, print);
	std::cout << '\n';
	iter(arr3, 4, print);
	std::cout << '\n';
}
