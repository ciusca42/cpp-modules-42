#include "../classes/Cat.hpp"
#include "../classes/Dog.hpp"
#include "../classes/Animal.hpp"
#include "../includes/colors.hpp"
#include <iostream>

void debugPrint(std::string name, int type) {

	std::string types[2] = {" constructor called\n", " destructor called\n"};

	std::cout << EMERALD300 << name << RESET << types[type];
}


int main()
{
	std::cout << YELLOW200 << "\n---------COSTRUCTORS--------\n" << RESET;

	// Animal anim;
	// Animal *anim2 = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << YELLOW200 << "\n---------TYPES--------\n" << RESET;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	std::cout << YELLOW200 << "\n---------MEMBER FUNCTIONS--------\n" << RESET;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	std::cout << "\n";

	std::cout << YELLOW200 << "\n---------DESTRUCTORS--------\n" << RESET;
	delete i;
	delete j;

	return 0;
}