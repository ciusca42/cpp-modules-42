#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {
	Zombie	zombie;

	zombie.setName(name);
	zombie.announce();
}