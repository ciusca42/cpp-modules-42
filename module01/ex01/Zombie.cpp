#include "Zombie.hpp"

Zombie::Zombie(): name("") {
	std::cout << "Creatin Basic Zombie\n";
}

Zombie::~Zombie ( void ) {
	std::cout << "Destroyng: " << this->name << '\n';
}

void Zombie::announce ( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}

void Zombie::setName (std::string name ) {
	this->name = name;
}

