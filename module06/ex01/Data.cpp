#include "Data.hpp"

Data::Data(void): name("None"), age(0), is_reptilian(false) {
	std::cout << "Data created\n";
}

Data::~Data(void) {
	std::cout << "Data destroyed\n";
}

Data::Data(const Data &obj) {
	*this = obj;
}

Data::Data(std::string name, int age, bool rept): name(name), age(age), is_reptilian(rept) {
	std::cout << "Data created\n";
}

std::string Data::getName(void) const {
	return this->name;
}

int Data::getAge(void) const {
	return this->age;
}

bool Data::getRept(void) const {
	return this->is_reptilian;
}

