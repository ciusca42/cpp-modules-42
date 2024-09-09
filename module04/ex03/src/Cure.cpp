#include "../classes/Cure.hpp"

Cure::Cure(void): AMateria("cure"), type("cure") {
	debugPrint("Cure", 0);
}

Cure::~Cure(void) {
	debugPrint("Cure", 1);
}

Cure::Cure(const Cure &obj) {
	*this = obj;
}

Cure & Cure::operator=(const Cure &obj) {
	this->type = obj.type;
	return *this;
}

AMateria* Cure::clone(void) const {
	AMateria *cloned = new Cure();
	
	return cloned;
}

void Cure::use(ICharacter &target) const {
	std::cout << LIME300 << '*' << RED200 << " heals " << RESET  << target.getName() << "'s wounds" << LIME300 << " *" << RESET << '\n';
}

std::string const & Cure::getType(void) const {
	return this->type;
}