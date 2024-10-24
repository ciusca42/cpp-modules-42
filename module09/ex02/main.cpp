#include "classes/PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe arr;
	int array[] = {7,8,27,100,11,46,2,53, 21, 44, 55, 66, 77, 88, 99};
	
	arr.setArr(array, 15);


	arr.sortVector();
	arr.sortDeque();

	return 0;

}