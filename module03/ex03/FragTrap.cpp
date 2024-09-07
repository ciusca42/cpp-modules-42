#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "none";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
	std::cout << "FragTrap default costrcutro called\n";
}

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
	std::cout << STONE300 << name << RESET << " <-- name [" << LIME300 << "FragTrap" << RESET << "] created\n"; 
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called\n";
}

FragTrap::FragTrap(const FragTrap &obj) {
	*this = obj;
}

FragTrap & FragTrap::operator=(const FragTrap &obj) {
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDmg = obj.attackDmg;
	this->name = obj.name;

	return *this;
}

void	FragTrap::highFiveGuys( void ) {
	std::cout << CYAN300 << "HighFive! " << RESET
	<< "You achived: " << ROSE300 << "5 guys!" << RESET << '\n';
}
