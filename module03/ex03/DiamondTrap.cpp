#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap(), FragTrap(), ScavTrap() {
	std::cout << YELLOW200 << "DiamondTrap basic costructor called\n";
}


/*
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
*/
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name) {
	this->_name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDmg = FragTrap::attackDmg;

	std::cout << "attackDmg diamond: " << this->attackDmg << '\n';

	std::cout << AMBER300 << name << RESET << " <-- name [" << GREEN300 << "DiamondTrap" << RESET << "] created\n";
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "ScavTrap destructo called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
	*this = obj;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &obj) {
	this->_name = obj.name;
	this->attackDmg = obj.attackDmg;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;

	return *this;
}

