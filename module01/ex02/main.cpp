#include <iostream>

typedef std::string str;

int main(void) {
	str brain = "HI THIS IS BRAIN";
	str &stringREF = brain;
	str *stringPTR = &brain;

	std::cout << &brain << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';

	std::cout << brain << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
}