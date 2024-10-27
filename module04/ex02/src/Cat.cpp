#include "../classes/Cat.hpp"
#include "../includes/colors.hpp"
#include <iostream>
#include <string>
// IWYU pragma: keep 

void debugPrint(std::string msg, int type);

Cat::Cat(void): Animal() {
	this->setType("Cat");
	this->type = "Cat";
	debugPrint("Cat", 0);
	this->_brain = new Brain();
}

Cat::~Cat() {
	debugPrint("Cat", 1);
	delete this->_brain;
}

Cat::Cat(const Cat &obj) {
	this->_brain = new Brain(*obj._brain);
}

Cat & Cat::operator=(const Cat &obj) {
	this->type = obj.type;
	delete this->_brain;

	this->_brain = new Brain(*obj._brain);

	return *this;
}

void Cat::makeSound(void) const {
		std::cout << PINK300 << "Meow Meow!\n" << RESET;
}
