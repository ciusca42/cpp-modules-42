#include "../classes/Ice.hpp"

Ice::Ice(void) {
	debugPrint("Ice", 0);
	this->type = "ice";
}

Ice::~Ice(void) {
	debugPrint("ice", 1);
}

Ice::Ice(const Ice &obj) {
	*this = obj;
}

Ice & Ice::operator=(const Ice &obj) {
	this->type = obj.type;
	return *this;
}

AMateria* Ice::clone(void) const {
	AMateria *cloned = new Ice();

	return cloned;
}
