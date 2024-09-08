#include "../classes/Cat.hpp"
#include "../classes/Dog.hpp"
#include "../classes/Animal.hpp"
#include "../includes/colors.hpp"
#include <iostream> // IWYU pragma: keep

void debugPrint(std::string name, int type) {

	std::string types[2] = {" constructor called\n", " destructor called\n"};

	std::cout << EMERALD300 << name << RESET << types[type];
}

int main()
{
	std::cout << YELLOW200 << "\n---------COSTRUCTORS--------\n" << RESET;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << YELLOW200 << "\n---------TYPES--------\n" << RESET;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << YELLOW200 << "\n---------MEMBER FUNCTIONS--------\n" << RESET;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << YELLOW200 << "\n---------DESTRUCTORS--------\n" << RESET;
	delete i;
	delete j;
	delete meta;

	return 0;
}