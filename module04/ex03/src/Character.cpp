#include "../classes/Character.hpp"
#include <cstddef>


void Character::initInventory(void) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(void): _name("None"), _nbMateria(0) {
	debugPrint("Character", 0);
	this->initInventory();
}

Character::~Character(void) {
	for (int i = 0; i < 3; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	debugPrint("Character", 1);
}

Character::Character(std::string name): _name(name), _nbMateria((0)) {
	debugPrint("Character: " + name, 0);
	this->initInventory();
}

Character::Character(const Character &obj) {
	*this = obj;
}

Character & Character::operator=(const Character &obj) {
	if (this == &obj)
		return *this;
	this->_name = obj._name;
	this->_nbMateria = obj._nbMateria;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = obj._inventory[i];
	}
	return *this;
}

std::string const & Character::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (this->_nbMateria >= 3) {
		std::cout << INDIGO300 << "The inventory is full\n" RESET;
		return ;
	}
	std::cout << EMERALD200 << m->getType() << YELLOW300 << ": Equiped!\n" << RESET;
	this->_inventory[this->_nbMateria++] = m;
}

AMateria *Character::saveMateria(int idx) {
	if (idx < 0 || idx > 4) {
		std::cerr << INDIGO300 << "Ivalid index\n" RESET;
		return NULL;
	}
	return this->_inventory[idx];
}

void Character::unequip(int idx) {
	if (idx > 4 || idx < 0 || idx >= this->_nbMateria) {
		std::cout << INDIGO300 << "Index out of range\n" RESET;
		return ;
	}
	if (this->_inventory[idx] == NULL) {
		std::cout << INDIGO300 << "No items to drop at this inded\n" RESET;
		return ;
	}
	std::cout << EMERALD200 << this->_inventory[idx]->getType() << ROSE200 << ": Unequiped!\n" << RESET;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx > 4 || idx < 0 || idx >= this->_nbMateria) {
		std::cout << INDIGO300 << "Index out of range\n" RESET;
		return ;
	}
	this->_inventory[idx]->use(target);
}