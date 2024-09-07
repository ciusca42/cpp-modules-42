#include "DiamondTrap.hpp"

int main(void) {
	FragTrap frag("carlos");
	ScavTrap scav("asteryx");
	DiamondTrap diamond("obelix");

	std::cout << '\n';
	
	scav.guardGate();
	frag.highFiveGuys();
	frag.attack("ciccio");
	diamond.attack("wall");
	diamond.highFiveGuys();

	std::cout << '\n';
	return 0;
}