#include "../classes/Form.hpp"
#include "../includes/colors.hpp"

Form::Form(void): _name(""), _signed(false), _execRequired(0), _signRequired(0) {
	std::cout << AMBER300 << "Form" << RESET << " constructor called\n";
}

Form::Form(std::string name, int grade): _name(name), _signed(false), _execRequired(0), _signRequired(grade) {
	this->checkGrade(grade);
	std::cout << AMBER300 << "Form" << RESET << " constructor called\n";
}

Form::~Form(void) {
	std::cout << AMBER300 << "Form" << RESET << " destructor called\n";
}

Form::Form(const Form &obj): _name(""), _signed(false), _execRequired(0), _signRequired(0)  {
	*this = obj;
}

Form &Form::operator=(const Form &obj) {
	if (this == &obj)
		return *this;
	this->_name = obj._name;
	this->_signed = obj._signed;
	return *this;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

const int Form::getExecRequired() const {
	return this->_execRequired;
}

const int Form::getSignRequired() const {
	return this->_signRequired;
}

void Form::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() <= this->_signRequired) {
		this->_signed = true;
		obj.signForm(*this);
		return ;
	}
	this->_signed = false;
	obj.signForm(*this);
	throw Form::GradeTooLow();
}

const char *Form::GradeTooLow::what() const throw() {
	return "Form not signed: Grade Too Low";
}

const char *Form::GradeTooHigh::what() const throw() {
	return "Form not signed: Grade Too High";
}

void Form::checkGrade(int grade) {
	if (grade <= 0)
		throw GradeTooHigh();
	else if (grade >= 151) {
		throw GradeTooLow();
	}
}

