#include "../classes/AForm.hpp"
#include "../includes/colors.hpp"

AForm::AForm(void): _name(""), _signed(false), _execRequired(0), _signRequired(0) {
	std::cout << AMBER300 << "AForm" << RESET << " constructor called\n";
}

AForm::AForm(std::string name, const int grade, const int exec): _name(name), _signed(false), _execRequired(exec), _signRequired(grade) {
	this->checkGrade(grade);
	std::cout << AMBER300 << "AForm" << RESET << " constructor called\n";
}

AForm::~AForm(void) {
	std::cout << AMBER300 << "AForm" << RESET << " destructor called\n";
}

AForm::AForm(const AForm &obj): _name(""), _signed(false), _execRequired(0), _signRequired(0)  {
	*this = obj;
}

AForm &AForm::operator=(const AForm &obj) {
	if (this == &obj)
		return *this;
	this->_name = obj._name;
	this->_signed = obj._signed;
	return *this;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

const int AForm::getExecRequired() const {
	return this->_execRequired;
}

const int AForm::getSignRequired() const {
	return this->_signRequired;
}

void AForm::setSign(bool sign) {
	this->_signed = sign;
}

void AForm::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() <= this->_signRequired) {
		this->_signed = true;
		obj.signForm(*this);
		return ;
	}
	this->_signed = false;
	obj.signForm(*this);
	throw AForm::GradeTooLow();
}

const char *AForm::GradeTooLow::what() const throw() {
	return "Form not signed: Grade Too Low";
}

const char *AForm::GradeTooHigh::what() const throw() {
	return "Form not signed: Grade Too High";
}

const char *AForm::NotSigned::what() const throw() {
	return "Form has not been signed before";
}

void AForm::checkGrade(int grade) {
	if (grade <= 0)
		throw GradeTooHigh();
	else if (grade >= 151) {
		throw GradeTooLow();
	}
}


