#include "ScavTrap.hpp"
#include "colors.hpp"

int main(void) {
	ClapTrap clap("bot");
	ScavTrap scav("superbot");
	std::cout << '\n';

	std::cout << LIME200 << "[SUPERBOT] [SPECIAL]\n" RESET;
	scav.guardGate();
	std::cout << '\n';
	for (int i = 0; i < 10; i++) {
		std::cout << LIME200 << "[BOT]\n" RESET;
		clap.attack("goomba");
		clap.takeDamage(2);
		clap.beRepaired(1);
		std::cout << '\n';
		std::cout << LIME200 << "[SUPERBOT]\n" RESET;
		scav.attack("superGoomba");
		scav.takeDamage(20);
		scav.beRepaired(10);
		std::cout << '\n';
	}
	std::cout << '\n';
	return 0;
}