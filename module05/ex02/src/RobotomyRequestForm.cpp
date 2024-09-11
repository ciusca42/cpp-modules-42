#include "../classes/forms/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45) {
	std::cout << CYAN200 << "RobotomyRequestForm" << RESET << " costructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << CYAN200 << "RobotomyRequestForm" << RESET << " destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm("RobotomyRequestForm", 72, 45) {
	*this = obj;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): _target(target), AForm("RobotomyRequestForm", 72, 745) {
	std::cout << CYAN200 << "RobotoyRequestForm" << RESET << " costructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this == &obj)
		return *this;
	std::string name;
	bool		sign;

	sign = obj.getSigned();

	this->_target = obj._target;
	this->setSign(sign);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &exec) const {
	static bool seeded = false;
	if (exec.getGrade() > this->getExecRequired()) {
		throw AForm::GradeTooLow();
		return ;
	}
	if (!this->getSigned()) {
		throw AForm::NotSigned();
		return ;
	}
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
	if (std::rand() % 2 == 0) {
		std::cout << LIME300 << this->_target << RESET << " has been " << ORANGE400 << "Robotomized\n" << RESET;
	}
	else
		std::cout << PURPLE200 << "Robotomy failed\n" RESET;
}
