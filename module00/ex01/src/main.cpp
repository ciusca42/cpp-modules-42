#include "../includes/phone.hpp"

void starting_print(void)
{

	// std::cout << LIME300" ________  ___  ___  ________  ________   ________  ________  ________  ___  __       \n";
	// std::cout << GREEN300"|\\   __  \\|\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   __  \\|\\   __  \\|\\   __  \\|\\  \\|\\  \\     \n";
	// std::cout << EMERALD300"\\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\/  /|_   \n";
	// std::cout << TEAL300" \\ \\   ____\\ \\   __  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\   __  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\   ___  \\\n";
	// std::cout << CYAN300"  \\ \\  \\___|\\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \n";
	// std::cout << SKY300"   \\ \\__\\    \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \\_______\\ \\_______\\ \\__\\\\ \\__\\ \n";
	// std::cout << INDIGO300"    \\|__|     \\|__|\\|__|\\|_______|\\|__| \\|__|\\|_______|\\|_______|\\|_______|\\|__| \\|__|\n\n";
	std::cout << VIOLET300"\t\t------------------------------------\n";
	std::cout << "\t\t|" RESET " Welcome to my personal phonebook " VIOLET300 "|\n";
	std::cout << "\t\t|     " SKY300 "Please select an option: " VIOLET300 "    |\n";
	std::cout << VIOLET300"\t\t------------------------------------\n" RESET;
	std::cout << "\t\t| " CYAN300 "1. Add a new contact |   ADD  " RESET "   |\n";
	std::cout << "\t\t| " CYAN300 "2. Search contact    |   SEARCH" RESET "  |\n";
	std::cout << "\t\t| " CYAN300 "3. Exit              |   EXIT " RESET "   |\n";
	std::cout << "\t\t------------------------------------\n\n";
	std::cout << STONE300;
}

#include <csignal>
#include <bits/stdc++.h>

void signal_handler(int signum)
{
	(void)signum;
	std::cout << "\n" RED700 BG_STONE500 "Exiting the phonebook" RESET "\n";
	_Exit(0);
}

void	menu() {
	PhoneBook phonebook;
	std::string option;

	while (1)
	{
		std::cout << STONE300 "[ ADD | SEARCH | EXIT ]: " RESET;
		getline(std::cin, option);
		if (std::cin.eof())
		{
			std::cout << '\n';
			break ;
		}
		std::cout << RESET;
		if (std::cin.eof())
			break ;
		if (option == "ADD")
			phonebook.add();
		else if (option == "SEARCH")
			phonebook.search();
		else if (option == "EXIT")
			break;
		else if (option == "")
			continue;
		else
			std::cout << ROSE300 "\nError: Invalid option\n\n" RESET;
	}
}

int main(void) {

	signal(2, signal_handler);
	starting_print();
	menu();
	std::cout << "\n" RED700 BG_STONE500 "Exiting the phonebook" RESET "\n";
	return 0;
}