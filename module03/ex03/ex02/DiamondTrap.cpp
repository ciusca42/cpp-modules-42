#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) {
	std::cout << YELLOW200 << "DiamondTrap basic costructor called\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name) {

}