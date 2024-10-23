#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap diamond("obelix");

	std::cout << '\n';
	
	diamond.whoami();
	std::cout << '\n';
	diamond.attack("LaPira");
	diamond.takeDamage(2);
	diamond.beRepaired(2);

	std::cout << '\n';
	return 0;
}