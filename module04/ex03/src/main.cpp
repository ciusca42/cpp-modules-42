#include "../includes/interface.hpp"
#include "../classes/Character.hpp"
#include "../classes/Ice.hpp"
#include "../classes/Cure.hpp"
#include "../classes/IMateriaSource.hpp"
#include "../classes/MateriaSource.hpp"

void debugPrint(std::string name, int type) {

	std::string types[2] = {" constructor called\n", " destructor called\n"};

	std::cout << EMERALD300 << name << RESET << types[type];
}
int main(void)
{
	std::cout << YELLOW300 << "\n---------COSTRUCTORS--------\n" << RESET;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	AMateria	*tmp, *tmp2;
	ICharacter* bob = new Character("bob");
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	int  curr = 0;
	AMateria	*ground[10];

	std::cout << YELLOW300 << "\n---------MEMBER FUNCTIONS--------\n" << RESET;

	src->learnMateria(ice);
	src->learnMateria(cure);

	std::cout << '\n';

	tmp = src->createMateria("ice");
	tmp2 = src->createMateria("cure");

	std::cout << '\n';

	me->equip(tmp);
	me->equip(tmp2);
	

	ground[curr++] = me->saveMateria(0);
	me->unequip(0);

	// for (int i = 0; i < 4; i++)
	// {
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// }

	//me->unequip(1);
	std::cout << '\n';
	/* me->use(0, *bob);
	me->use(1, *bob); */
	for (int i = curr ; i >= 0; i--) {
		delete ground[i];
	}

	std::cout << YELLOW300 << "\n---------DESTRUCTORS--------\n" << RESET;
	delete bob;
	delete me;
	delete src;
	return 0;
}