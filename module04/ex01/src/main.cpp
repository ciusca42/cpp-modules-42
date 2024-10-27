#include "../classes/Cat.hpp"
#include "../classes/Dog.hpp"
#include "../classes/Animal.hpp"
#include "../includes/colors.hpp"
#include <iostream> // IWYU pragma: keep

void debugPrint(std::string name, int type) {

	std::string types[2] = {" constructor called\n", " destructor called\n"};

	std::cout << EMERALD300 << name << RESET << types[type];
}

#define TOT 4

int main()
{
	std::cout << YELLOW300 << "\n---------COSTRUCTORS--------\n" << RESET;
	Animal *animals[TOT];

	for (int i = 0; i < TOT; i++) {
		if (i < TOT / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << YELLOW300 << "\n---------TYPES--------\n" << RESET;
	for (int i = 0; i < TOT; i++) {
		std::cout << ROSE200 << i << ": " << RESET;
		std:: cout << animals[i]->getType() << '\n';
	}

	std::cout << YELLOW300 << "\n---------MEMBER FUNCTIONS--------\n" << RESET;
	for (int i = 0; i < TOT; i++) {
		std::cout << ROSE200 << i << ": ";
		animals[i]->makeSound();
	}
	std::cout << YELLOW300 << "\n---------DESTRUCTORS--------\n" << RESET;
	
	for (int i = 0; i < TOT; i++)
		delete animals[i];

	return 0;
}