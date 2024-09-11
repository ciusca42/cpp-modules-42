#include "../includes/colors.hpp"
#include "../classes/Bureaucrat.hpp"
#include "../classes/forms/ShrubberyCreationForm.hpp" // IWYU pragma: keep
#include "../classes/forms/RobotomyRequestForm.hpp"
#include "../classes/forms/PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main(void) {

	std::cout << CYAN400 << "\n----------CONSTRUCTORS----------\n" << RESET;
	Bureaucrat buro("ciuschi", 1);
	Bureaucrat mad("gary", 148);
	AForm *form = new RobotomyRequestForm("home");
	AForm *other = new PresidentialPardonForm("president");\
	AForm *tree = new ShrubberyCreationForm("home");
	std::cout << '\n';
	
	std::cout << CYAN400 << "\n----------ROBOTOMY----------\n" << RESET;
	try {
		form->beSigned(buro);
	} catch (std::exception &e) {
		std::cerr << ROSE200 << e.what() << '\n' << RESET;
	}

	std::cout << '\n';

	for (int i = 0; i < 5; i++) {
		form->execute(buro);
	}
	//tree->beSigned(buro);
	std::cout << CYAN400 << "\n----------CHECK EXCEPTION----------\n" << RESET;
	std::cout << '\n';
	try {
		other->beSigned(mad);
	} catch (std::exception &e) {
		std::cout << '\n';
		std::cerr << ROSE200 << e.what() << '\n' << RESET;
		std::cout << '\n';
	}

	std::cout << CYAN400 << "\n----------TREE----------\n" << RESET;
	try {
		tree->beSigned(buro);
	} catch (std::exception &e) {
		std::cerr << ROSE200 << e.what() << '\n' << RESET;
	}

	std::cout << CYAN200 << "Creating Tree...\n" << RESET;
	tree->execute(buro);

	

	std::cout << CYAN400 << "\n----------DESTRUCTORS----------\n" << RESET;
	delete form;
	delete other;
	delete tree;
	return 0;
}