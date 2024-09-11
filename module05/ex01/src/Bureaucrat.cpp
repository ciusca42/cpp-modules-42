#include "../classes/Bureaucrat.hpp"
#include "../classes/Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void): _name(""), _grade(150) {
	checkGrade();
	std::cout << CYAN200 << "Bureaucrat" << RESET << " constructor called\n";
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << CYAN200 << "Bureaucrat" << RESET << " destructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	checkGrade();
	std::cout << CYAN200 << "Bureaucrat" << RESET << " constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
	*this = obj;
	checkGrade();
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this == &obj)
		return *this;
	this->_grade = obj._grade;
	this->_name = obj._name;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (--this->_grade <= 0)
		throw GradeTooHigh();
	std::cout << PURPLE200 << "grade [INCREMENTED]\n" << RESET;
}

void Bureaucrat::decrementGrade() {
	if (++this->_grade >= 151)
		throw GradeTooLow();
	std::cout << PURPLE200 << "grade [DECREMENTED]\n" << RESET;
}


std::ostream & operator<<(std::ostream &out, Bureaucrat &obj) {
	out << ORANGE200 << obj.getName() << RESET << ", Bureaucrat grade: " << LIME200 << obj.getGrade() << RESET << '\n';
	return out;
}

void Bureaucrat::signForm(const Form &obj) const {
	if (obj.getSigned()) {
		std::cout << AMBER300 << this->_name << RESET << " signed " << ORANGE400 << obj.getName() << RESET << '\n';
		return ;
	}
	std::cout << AMBER300 << this->_name << RESET << " couldn't sign " << ORANGE400 << obj.getName() << RESET;
	std::cout << " becouse: " << YELLOW200 << "he is not powerful enough\n" << RESET;
}

const char * Bureaucrat::GradeTooHigh::what() const throw() {
	return "Grade Too High exception\n";
}

const char * Bureaucrat::GradeTooLow::what() const throw() {
	return "Grade Too Low exception\n";
}

void Bureaucrat::checkGrade() {
	if (this->_grade <= 0)
		throw GradeTooHigh();
	else if (this->_grade >= 151) {
		throw GradeTooLow();
	}
}



