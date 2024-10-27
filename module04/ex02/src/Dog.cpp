#include "../classes/Dog.hpp"
#include "../includes/colors.hpp"
#include <iostream>

void debugPrint(std::string msg, int type);
Dog::Dog(): Animal() {
	setType("Dog");
	this->type = "Dog";
	debugPrint("Dog", 0);
	this->_brain = new Brain();
}

Dog::~Dog() {
	debugPrint("Dog", 1);
	delete this->_brain;
}

Dog::Dog(const Dog &obj) {
	this->_brain = new Brain(*obj._brain);
}

Dog & Dog::operator=(const Dog &obj) {
	this->type = obj.type;
	delete this->_brain;

	this->_brain = new Brain(*obj._brain);

	return *this;
}

void Dog::makeSound(void) const {
		std::cout << PINK300 << "Bau Bau!\n" << RESET;
}

