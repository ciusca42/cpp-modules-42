#include "../includes/interface.hpp"

void debugPrint(std::string name, int type) {

	std::string types[2] = {" constructor called\n", " destructor called\n"};

	std::cout << EMERALD300 << name << RESET << types[type];
}

