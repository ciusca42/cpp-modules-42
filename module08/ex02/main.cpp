#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	MutantStack<int>::iterator start = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	while (start != end) {
		std::cout << "empyt MutantStack\n";
		std::cout << *start << std::endl;
		++start;
	}

	mstack.push(5);
	mstack.push(17);

	for (int i = 0; i < 12; i++) {
		mstack.push(i);
	}
	std::cout << "size: ";
	std::cout << mstack.size() << std::endl;
	std::cout << "top: ";
	std::cout << mstack.top() << std::endl;
	std::cout << "removing element...\n";
	mstack.pop();
	std::cout << "top again: ";
	std::cout << mstack.top() << std::endl;
	std::cout << "size: ";
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	
	return 0;
}