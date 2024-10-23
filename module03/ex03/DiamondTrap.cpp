#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap(), FragTrap(), ScavTrap() {
	std::cout << YELLOW200 << "DiamondTrap basic costructor called\n";
}


/*
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
*/
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name) {
	this->_name = ClapTrap::name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDmg = FragTrap::attackDmg;
	this->maxHealth = this->hitPoints;

	std::cout << AMBER300 << name << RESET << " <-- name [" << GREEN300 << "DiamondTrap" << RESET << "] created\n";
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called\n";
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

void DiamondTrap::whoami() { 
	std::cout << CYAN200 << "Diamond name => " RESET << this->_name << CYAN200 " Clap name => " RESET << ClapTrap::name + "_clap_name" << '\n';  
}

