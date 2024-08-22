#include "Zombie.hpp"

Zombie*	zombieHorde( int n, std::string name ) {
	Zombie *hord = new Zombie[n];

	for (int i = 0; i < n; i++) {
		hord[i].setName(name);
	}
	return hord;
}