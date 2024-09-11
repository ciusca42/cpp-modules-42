#include "../classes/Intern.hpp"
#include "../classes/forms/ShrubberyCreationForm.hpp"
#include "../classes/forms/PresidentialPardonForm.hpp"
#include "../classes/forms/RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern(void) {
	std::cout << LIME200 << "Intern " << RESET << "constructor called\n";
}

Intern::~Intern(void) {
	std::cout << LIME200 << "Intern " << RESET << "constructor called\n";
}

Intern::Intern(std::string name, std::string target) {
	this->makeForm(name, target);
}

Intern::Intern(const Intern &obj) {
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target) {
	AForm *	form = NULL;
	AForm *	(Intern::*funcPtr[3])(std::string targ) const = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string	 known[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++) {
		if (name == known[i]) {
			form = (this->*funcPtr[i])(target);
			std::cout << "Intern created a new form\n";
			return form;
		}
	}
	std::cerr << ROSE200 << "Invalid form name\n" << RESET;
	throw InvalidForm();
	return NULL;
}

const char *Intern::InvalidForm::what() const throw() {
	return "form not created: Invalid name";
}

AForm *Intern::makePresidential(std::string target) const {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubbery(std::string target) const {
	return new ShrubberyCreationForm(target);
}