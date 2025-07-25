#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl ( void ) {}

void Harl::complain ( std::string level ) {
	void	(Harl::*funcPtr)(void) const = NULL;
	void	(Harl::*funcArray[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[4] = {"debug", "info", "warning", "error"};
	int					i;

	for (i = 0; i < 4; i++) {
		if (level == levels[i]) {
			funcPtr = funcArray[i];
			break;
		}
	}
	if (i == 4) {
		std::cerr << ROSE300 "Do want to complaing even more?!!\n" RESET;
		return;
	}
	(this->*funcPtr)();

}

void Harl::debug ( void ) const {
	std::cout <<  EMERALD300 "[DEBUG]" RESET "\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << '\n';
}

void Harl::info ( void ) const {
	std::cout << EMERALD300 "[INFO]" RESET "\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! \n";
}

void Harl::warning ( void ) const {
	std::cout << EMERALD300 "[WARNING]" RESET "\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error ( void ) const {
	std::cout << EMERALD300 "[ERROR]" RESET "\nThis is unacceptable! I want to speak to the manager now.\n";
}