#include "../classes/forms/ShrubberyCreationForm.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 72, 45) {
	std::cout << CYAN200 << "ShrubberyCreationForm" << RESET << " costructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << CYAN200 << "ShrubberyCreationForm" << RESET << " destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm("ShrubberyCreationForm", 72, 45) {
	*this = obj;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _target(target), AForm("ShrubberyCreationForm", 72, 745) {
	std::cout << CYAN200 << "ShrubberyCreationForm" << RESET << " costructor called\n";
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this == &obj)
		return *this;

	bool		sign = obj.getSigned();

	this->_target = obj._target;
	this->setSign(sign);

	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &exec) const {
	if (exec.getGrade() > this->getExecRequired()) {
		throw AForm::GradeTooLow();
		return ;
	}
	if (!this->getSigned()) {
		throw AForm::NotSigned();
		return ;
	}
	std::string filename = "export FILENAME=" + this->_target + "_shrubbery";
	system(filename.c_str());
	system("./bonsai.sh -g 50 | sed '1,26d' | head -n -3  > $FILENAME");
}
