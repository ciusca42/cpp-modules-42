#include "../classes/MateriaSource.hpp"


MateriaSource::MateriaSource(): _nbKnown(0) {
	debugPrint("MateriaSource", 0);
	for (int i = 0; i < 4; i++) {
		this->_known[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	debugPrint("MateriaSource", 1);
	for (int i = 0; i < 4; i++) {
		delete this->_known[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj): _nbKnown(obj._nbKnown) {
	for (int i = 0; i < 4; i++) {
		delete this->_known[i];
		this->_known[i] = obj._known[i]->clone();
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &obj) {
	if (this == &obj)
		return *this;
	for (int i = 0; i < 4; i++) {
		delete  this->_known[i];
		this->_known[i] = obj._known[i]->clone();
	}
	this->_nbKnown = obj._nbKnown;
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (this->_nbKnown >= 3) {
		std::cout << INDIGO300 << "Materia inventory is full\n" << RESET;
		return ;
	}
	std::cout << VIOLET300 << "Learning materia... -> " << CYAN200 << m->getType() << '\n' << RESET;
	this->_known[this->_nbKnown++] = m;
}

AMateria* MateriaSource::createMateria(std::string const  &type) {
	AMateria *created;
	for (int i = 0; i < this->_nbKnown; i++) {
		if (type == this->_known[i]->getType()) {
			std::cout << STONE200 << "Creating... -> " << YELLOW300 << type << '\n' << RESET;
			created = this->_known[i]->clone(); 
			return created;
		}
	}
	std::cout << INDIGO300 << "Materia not found\n" << RESET;
	return NULL;
}