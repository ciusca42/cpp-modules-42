#include "Harl.hpp"
#include "colors.hpp"

Harl::Harl( void ) {}

Harl::~Harl ( void ) {}

void Harl::complain ( std::string level )  {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					i;

	for (i = 0; i < 4; i++) {
		if (levels[i] == level)
			break;
	}

	switch (i)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break;
	default:
		std::cout << YELLOW200 << "how many complaints do you want? arn't already to much??\n" RESET;
		break;
	}
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