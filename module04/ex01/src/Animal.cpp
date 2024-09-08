#include "../classes/Animal.hpp"
#include "../includes/colors.hpp"
#include <iostream>

void debugPrint(std::string msg, int type);

Animal::Animal(): type("Animal") {
	debugPrint("Animal", 0);
}

Animal::~Animal() {
	debugPrint("Animal", 1);
}

Animal::Animal(const Animal &obj) {
	*this = obj;
}

Animal & Animal::operator=(const Animal &obj) {
	this->type = obj.type;
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << PINK300 << "lsdj%@#$@#^\n" << RESET;
}

std::string Animal::getType(void) const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}