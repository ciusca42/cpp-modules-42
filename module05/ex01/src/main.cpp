#include "../includes/colors.hpp"
#include "../classes/Bureaucrat.hpp"
#include "../classes/Form.hpp"
#include <exception>
#include <iostream>

int main(void) {
	Bureaucrat buro("ciuschi", 1);
	Bureaucrat mad("gary", 148);
	Form paper("petition", 15);
	Form contract("important contract", 150);
	std::cout << '\n';
	
	try {
		contract.beSigned(buro);
		paper.beSigned(mad);
	} catch (std::exception &exc) {
		std::cerr << ROSE300 << "\nException: " << RESET;
		std::cerr << exc.what() << '\n';
	}

	//buro.signForm(paper);
	//buro.signForm(contract);
	//mad.signForm(paper);
	std::cout << '\n';

	buro.decrementGrade();
	std::cout << buro << '\n';
	for (int i = 0; i < 4; i++) {
		try {
			buro.incrementGrade();
			std::cout << buro << '\n';
		}
		catch (const std::exception &e) {
			std::cerr << ROSE300 << "Error: " << RESET;
			std::cerr << e.what() << '\n';
			break;
		}
	}
}