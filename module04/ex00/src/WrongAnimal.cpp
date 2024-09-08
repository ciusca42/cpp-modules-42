#include "../wrong/WrongAnimal.hpp"

void debugPrint(std::string msg, int type);

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
	debugPrint("WrongAnimal", 0);
}

WrongAnimal::~WrongAnimal() {
	debugPrint("WrongAnimal", 1);
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	*this = obj;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &obj) {
	this->_type = obj._type;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << PINK300 << "Wrong Wrong!\n" << RESET;
}

std::string WrongAnimal::getType(void) const {
	return this->_type;
}

void WrongAnimal::setType(std::string type) {
	this->_type = type;
}