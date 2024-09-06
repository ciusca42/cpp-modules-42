#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "Basic ScavTrap created\n";
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name) {
	std::cout << STONE300 << this->getName() << RESET << " <-- name [";
	std::cout << EMERALD400 << "ScavTrap" << RESET << "] created\n";
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	this->setAtkDmg(20);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack( const std::string &target) {
	int hitPoints = getHitPoints();
	int energyPoints = getEnergyPoints();
	std::string name = getName();
	int attackDmg = getAttackDmg();
	
	if (hitPoints <= 0) {
		diePrint();
	return ;
	}
	if (energyPoints <= 0) { 
		noEnergy();
	return ;
	}
	energyPoints--;
	setEnergyPoints(energyPoints);
	std::cout << ORANGE400 << name << RESET << " ";
	std::cout << "is raging at: " << EMERALD400 << target << RESET;
	std::cout << ", causing: " << LIME300 << attackDmg << RESET << " points of damage!\n";

}

void ScavTrap::guardGate( void ) {
	std::cout << CYAN300 << "GuardGate" << RESET << " activated!"
		<< " You shall not pass!!\n";
}