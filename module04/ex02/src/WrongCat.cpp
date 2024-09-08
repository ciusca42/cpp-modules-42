#include "../wrong/WrongCat.hpp"
#include "../includes/colors.hpp"
#include <iostream>
// IWYU pragma: keep 

void debugPrint(std::string msg, int type);
WrongCat::WrongCat(void): WrongAnimal() {
	setType("WrongCat");
	this->_type = "WrongCat";
	debugPrint("WrongCat", 0);
}

WrongCat::~WrongCat() {
	debugPrint("WrongCat", 1);
}

WrongCat::WrongCat(const WrongCat &obj) {
	*this = obj;
}

WrongCat & WrongCat::operator=(const WrongCat &obj) {
	this->_type = obj._type;
	return *this;
}

void WrongCat::makeSound(void) const {
		std::cout << PINK300 << "Wong Meow!\n" << RESET;
}

std::string WrongCat::getType(void) const {
	return this->_type;
}