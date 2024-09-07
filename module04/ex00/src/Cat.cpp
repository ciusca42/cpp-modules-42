#include "../classes/Cat.hpp"
#include "../includes/colors.hpp"
#include <iostream>
// IWYU pragma: keep 

void debugPrint(std::string msg, int type);
Cat::Cat(void): Animal() {
	setType("Cat");
	this->type = "Cat";
	debugPrint("Cat", 0);
}

Cat::~Cat() {
	debugPrint("Cat", 1);
}

Cat::Cat(const Cat &obj) {
	*this = obj;
}

Cat & Cat::operator=(const Cat &obj) {
	this->type = obj.type;
	return *this;
}

void Cat::makeSound(void) const {
		std::cout << PINK300 << "Meow Meow!\n" << RESET;
}