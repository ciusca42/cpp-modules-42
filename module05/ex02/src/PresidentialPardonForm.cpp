#include "../classes/forms/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 72, 45) {
	std::cout << CYAN200 << "PresidentialPardonFrom" << RESET << " costructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << CYAN200 << "PresidentialPardonFrom" << RESET << " destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm("PresidentialPardonForm", 72, 45) {
	*this = obj;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): _target(target), AForm("PardonForm", 72, 745) {
	std::cout << CYAN200 << "RobotoyRequestForm" << RESET << " costructor called\n";
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this == &obj)
		return *this;
	std::string name;
	
	bool		sign = getSigned();

	this->setSign(sign);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecRequired()) {
		throw AForm::GradeTooLow();
		return ;
	}
	if (!this->getSigned()) {
		throw AForm::NotSigned();
		return ;
	}
	std::cout << CYAN300 << this->_target << RESET << " Has been pardones by: " << LIME300 << "Zaphod Beeblebrox\n" << RESET; 
}
