#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout << "Basic ScavTrap created\n";
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name) {
	this->energyPoints = 50;
	this->hitPoints = 100;
	this->attackDmg = 20;
	this->name = name;
	std::cout << STONE300 << name << RESET << " <-- name [";
	std::cout << EMERALD400 << "ScavTrap" << RESET << "] destroyed\n";
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
	this->attackDmg = obj.attackDmg;
	this->name = obj.name;
	return *this;
}

void ScavTrap::attack( const std::string &target) {
	
	if (hitPoints <= 0) {
		diePrint();
	return ;
	}
	if (energyPoints <= 0) { 
		noEnergy();
	return ;
	}
	this->energyPoints--;
	std::cout << ORANGE400 << name << RESET << " ";
	std::cout << "is raging at: " << EMERALD400 << target << RESET;
	std::cout << ", causing: " << LIME300 << attackDmg << RESET << " points of damage!\n";

}

void ScavTrap::guardGate( void ) {
	std::cout << CYAN300 << "guardGate activated!" << RESET
		<< " You shall not pass!!\n";
}