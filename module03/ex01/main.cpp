#include "ScavTrap.hpp"

int main(void) {
	ClapTrap clap("bot");
	ScavTrap scav("superbot");

	clap.attack("goomba");
	scav.attack("superGoomba");
	return 0;
}