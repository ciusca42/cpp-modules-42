#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include "../includes/colors.hpp" // IWYU pragma: keep

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat & operator=(const Bureaucrat &obj);
	
		std::string getName() const;
		int			getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(const Form &obj) const; 

	private:
		void	checkGrade();
		std::string _name;
		int			_grade;

	class GradeTooHigh: public std::exception {
		 const char *what() const throw();
	};
	class GradeTooLow: public std::exception {
		const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream &out, Bureaucrat &obj);

#endif


