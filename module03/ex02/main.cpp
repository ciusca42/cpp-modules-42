#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap frag("carlos");
	ScavTrap scav("asteryx");

	std::cout << '\n';
	
	scav.guardGate();
	frag.highFiveGuys();
	frag.attack("ciccio");

	std::cout << '\n';
	return 0;
}