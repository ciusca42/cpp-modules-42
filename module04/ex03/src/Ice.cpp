#include "../classes/Ice.hpp"

Ice::Ice(void): AMateria("ice"), type("ice") {
	debugPrint("Ice", 0);
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

void Ice::use(ICharacter &target) const {
	std::cout << LIME300 << "* " << RESET << "shoots an " << CYAN400 << "ice bolt" << RESET << " at " << target.getName() << LIME300 << " *" << RESET << '\n';
}

std::string const & Ice::getType(void) const {
	return this->type;
}
