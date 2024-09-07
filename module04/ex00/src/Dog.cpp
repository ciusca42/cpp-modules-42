#include "../classes/Dog.hpp"
#include "../includes/colors.hpp"
#include <iostream>

void debugPrint(std::string msg, int type);
Dog::Dog(): Animal() {
	setType("Dog");
	this->type = "Dog";
	debugPrint("Dog", 0);
}

Dog::~Dog() {
	debugPrint("Dog", 1);
}

Dog::Dog(const Dog &obj) {
	*this = obj;
}

Dog & Dog::operator=(const Dog &obj) {
	this->type = obj.type;
	return *this;
}

void Dog::makeSound(void) const {
		std::cout << PINK300 << "Bau Bau!\n" << RESET;
}

