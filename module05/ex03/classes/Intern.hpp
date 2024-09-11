#ifndef INTER_HPP
# define INTER_HPP

#include "AForm.hpp"
#include <exception>

class Intern {
	public:
		Intern();
		Intern(std::string name, std::string target);
		~Intern();
		Intern(const Intern &obj);
		Intern & operator=(const Intern &obj);

		AForm *makeForm(std::string name, std::string target);

		class InvalidForm: public std::exception {
			const char *what() const throw();
		};
	private:
		AForm *		makePresidential(std::string target) const;
		AForm *		makeRobotomy(std::string target) const;
		AForm *		makeShrubbery(std::string target) const;
};

#endif