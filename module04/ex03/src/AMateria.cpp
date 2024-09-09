#include "../classes/AMateria.hpp"

AMateria::AMateria(): type("None") {
	debugPrint("Materia", 0);	
}

AMateria::~AMateria() {
	debugPrint("Materia", 1);
}

AMateria::AMateria(std::string const &type): type(type) {
	debugPrint("Materia: " + type, 0);
}

AMateria::AMateria(const AMateria &obj) {
	*this = obj;
}

void AMateria::use(ICharacter &target) const {
	std::cout << "Can't use this, im not a specified materia!\n";
}

std::string const & AMateria::getType(void) const {
	return this->type;
}
