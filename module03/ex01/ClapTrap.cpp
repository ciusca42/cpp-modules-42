#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ): name(name), hitPoints(10), energyPoints(10), attackDmg(0), maxHealth(10) {
	std::cout << STONE300 << name << RESET << " <-- name [" << LIME300 << "ClapTrap" << RESET << "] created\n";  
}

ClapTrap::ClapTrap( void ): name("none"), hitPoints(10), energyPoints(10), attackDmg(0) {
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
	if (this->hitPoints > maxHealth)
		this->hitPoints = maxHealth;
	std::cout << ORANGE400 << "Repairing... " <<  RESET << "adding: " << VIOLET400 << amount << RESET;
	std::cout << " hitPoints\n";
	std::cout << STONE300 << "Current hitPoints: " << LIME300 << this->hitPoints << '\n' << RESET;
}
