#include "ClapTrap.hpp"
#include <algorithm>
#include <string>
#include <vector>

int confirmName(std::string name) {
	std::string action;
	while (1) {
		std::cout << "you inserted: " LIME300 << name << RESET << " are you sure? " << EMERALD400 << "[y/n] " << RESET;
		getline(std::cin, action);
		if (action == "y" || action == "yes")
			return 1;
		else if (action == "n" || action == "no")
			return 0;
	}
	return 0;
}

int parseInt(void) {
	std::string input;
	int	dmg;

	while (1) {
		std::cout << LIME200 <<  "insert the amount: " << RESET;
		getline(std::cin, input);
		dmg = atoi(input.c_str());
		if ((dmg == 0 && input != "0" ) || dmg < 1 ) {
			std::cout << ROSE300 "insert a valid input!\n" RESET;
			continue;
		}
		std::cout << '\n';
		return dmg;
	}
	return dmg;
}

int main(int argc, char **argv) {
	ClapTrap clap("bot");
	std::cout << '\n';

	for (int i = 0; i < 9; i++) {
		std::cout << LIME200 << "[BOT]\n" RESET;
		clap.attack("goomba");
		clap.takeDamage(2);
		clap.beRepaired(1);
		std::cout << '\n';
	}
	std::cout << '\n';
	return 0;
	return 0;
}