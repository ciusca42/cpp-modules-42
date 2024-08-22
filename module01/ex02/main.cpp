#include <iostream>

typedef std::string str;

int main(void) {
	str brain = "HI THIS IS BRAIN";
	str *stringPTR = &brain;
	str &stringREF = brain;

	std::cout << &brain << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';

	std::cout << brain << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
}