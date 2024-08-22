#include "Zombie.hpp"

int	main() {
	Zombie	*z = NULL;
	Zombie	*hord = NULL;

	z = z->newZombie("gary");
	z->randomChump("john");
	hord = zombieHorde(10, "cavins");
	delete z;
	delete[] hord;
}