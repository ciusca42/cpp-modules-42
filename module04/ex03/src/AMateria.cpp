#include "../classes/AMateria.hpp"

AMateria::AMateria(): type("None") {
	debugPrint("Materia", 0);
}

AMateria::~AMateria() {
	debugPrint("Materia", 1);
}

AMateria::AMateria(std::string const &type): type(type) {
	debugPrint("Materia Type", 0);
}

AMateria::AMateria(const AMateria &obj) {
	*this = obj;
}

AMateria & AMateria::operator=(const AMateria &obj) {
	return *this;
}

void AMateria::use(ICharacter &target) {}
