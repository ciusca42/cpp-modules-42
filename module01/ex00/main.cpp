#include "Zombie.hpp"

int	main() {
	Zombie	*z = NULL;

	z = z->newZombie("gary");
	z->randomChump("john");

	delete z;
}