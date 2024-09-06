#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAtkDmg(30);
		std::cout << STONE300 << name << RESET << " <-- name [" << LIME300 << "FragTrap" << RESET << "] created\n"; 
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called\n";
}

FragTrap::FragTrap(const FragTrap &obj) {
	*this = obj;
}

FragTrap & FragTrap::operator=(const FragTrap &obj) {
	int hit, enrg, atk;
	std::string name;

	hit = obj.getHitPoints();
	enrg = obj.getEnergyPoints();
	atk = obj.getAttackDmg();
	name = obj.getName();
	
	this->setAtkDmg(atk);
	this->setEnergyPoints(enrg);
	this->setHitPoints(hit);
	this->setName(name);
	return *this;
}

void	FragTrap::highFiveGuys( void ) {
	std::cout << CYAN300 << "HighFive! " << RESET
	<< "You achived: " << ROSE300 << "5 guys!" << RESET << '\n';
}
