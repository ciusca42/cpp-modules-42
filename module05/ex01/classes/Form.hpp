#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream> // IWYU pragma: keep



class Form {
	public:
		Form();
		Form(std::string name, int grade);
		~Form();
		Form(const Form &obj);
		Form & operator=(const Form &obj);

		std::string getName() const;
		bool getSigned() const;
		const int getExecRequired() const;
		const int getSignRequired()  const;

		void beSigned(const Bureaucrat &obj);

		class GradeTooHigh: public std::exception {
		 	const char *what() const throw();
		};
		class GradeTooLow: public std::exception {
			const char *what() const throw();
		};

	private:
		void		checkGrade(int grade);
		std::string _name;
		bool 		_signed;
		const int	_execRequired;
		const int	_signRequired;
};

std::ostream operator<<(std::ostream &out, const Form &obj);

#endif