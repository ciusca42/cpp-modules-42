#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ): name(name), hitPoints(10), energyPoints(10), attackDmg(0) {
	std::cout << STONE300 << name << RESET << " <-- name [" << LIME300 << "ClapTrap" << RESET << "] created\n";  
}

ClapTrap::ClapTrap( void ) {
	std::cout << "Basic ClapTrap created\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called\n";
}

void ClapTrap::diePrint( void ) {
	std::cout << ROSE200 << "You Died!" STONE400 << " You cannot perform actions when you are dead.\n" RESET;
}

void ClapTrap::noEnergy( void ) {
	std::cout << STONE400 << "Not enough energy points\n" RESET;
}

void ClapTrap::attack( const std::string &target ) {
	if (this->hitPoints <= 0) {
		diePrint();
		return ;
	}
	if (this->energyPoints <= 0) { 
		noEnergy();
		return ;
	}
	this->energyPoints--;
	std::cout << ORANGE400 << this->name << RESET << " ";
	std::cout << "Attacks: " << EMERALD400 << target << RESET;
	std::cout << ", causing: " << LIME300 << this->attackDmg << RESET << " points of damage!\n";
}

void ClapTrap::takeDamage( unsigned int amount ) {

	if (this->hitPoints <= 0) {
		diePrint();
		return;
	}
	if (this->energyPoints <= 0) {
		return ;
	}
	std::cout << ORANGE400 << this->name << RESET << " ";
	std::cout << "Takes: " << EMERALD400 << amount << RESET;
	std::cout << " of damage\n" << RESET;
	this->hitPoints -= amount;
	if (hitPoints <= 0) {
		std::cout << ORANGE400 << this->name << " " << RESET << ROSE400 << "Died!" << RESET << '\n';
		return ;
	}
	std::cout << STONE300 "Current hitpoints: " << CYAN300 << this->hitPoints << RESET << '\n';
}

void ClapTrap::beRepaired ( unsigned int amount ) {

	if (this->hitPoints <= 0) {
		diePrint();
		return ;
	}
	if (this->energyPoints <= 0) {
		noEnergy();
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	if (this->hitPoints > 10)
		this->hitPoints = 10;
	std::cout << ORANGE400 << "Repairing... " <<  RESET << "adding: " << VIOLET400 << amount << RESET;
	std::cout << " hitPoints\n";
	std::cout << STONE300 << "Current hitPoints: " << LIME300 << this->hitPoints << '\n' << RESET;
}

void ClapTrap::setAtkDmg( unsigned int amount ) {
	this->attackDmg = amount;
}

void ClapTrap::setHitPoints(unsigned int amount ) {
	this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
	this->energyPoints = amount;
}

void ClapTrap::setName(std::string name) {
	this->name = name;
}

std::string ClapTrap::getName(void) const {
	return this->name;
}

int	ClapTrap::getHitPoints(void) const {
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints(void) const {
	return this->energyPoints;
}

int ClapTrap::getAttackDmg(void) const {
	return this->attackDmg;
}
