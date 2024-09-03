#include "ClapTrap.hpp"
#include <string>

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
	std::string input, name, dmg;

	while (1) {
		std::cout << PURPLE300 << "\n\tCreate a ClapTrap\n\n" << RESET;
		std::cout << STONE300 << "insert the name: " << RESET;
		getline(std::cin, name);
		if (name == "") {
			system("clear");
			continue;
		}
		if (confirmName(name) == 1)
			break;
	}
	ClapTrap bot(name);
	std::cout << CYAN400 << "\nSet the damage points\n\n" << RESET;
	bot.setDmg(parseInt());
	std::cout << "hello\n";
	while (1) { 
		std::cout << ROSE200 << "Insert the action: <attack> | <damage> | <repair> | exit | " RESET;
		getline(std::cin, input);
		if (input == "")
			continue;
		else if (input == "attack")
			bot.attack("enemy");
		else if (input == "damage")
			bot.takeDamage(parseInt());
		else if (input == "repair")
			bot.beRepaired(parseInt());
		if (input == "exit")
			break;
	}
	return 0;
}