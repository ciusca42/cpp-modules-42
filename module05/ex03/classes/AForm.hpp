#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream> // IWYU pragma: keep

class AForm {
	public:
		AForm();
		AForm(std::string name, const int grade, const int exec);
		virtual ~AForm();
		AForm(const AForm &obj);
		AForm & operator=(const AForm &obj);

		std::string getName() const;
		bool getSigned() const;
		const int getExecRequired() const;
		const int getSignRequired()  const;

		void setSign(bool sign);

		void beSigned(const Bureaucrat &obj);
		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooHigh: public std::exception {
		 	const char *what() const throw();
		};

		class GradeTooLow: public std::exception {
			const char *what() const throw();
		};
		
		class NotSigned: public std::exception {
			const char *what() const throw();
		};

	private:
		void		checkGrade(int grade);
		std::string _name;
		bool 		_signed;
		const int	_execRequired;
		const int	_signRequired;
};

std::ostream operator<<(std::ostream &out, const AForm &obj);

#endif