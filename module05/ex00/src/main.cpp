#include "../includes/colors.hpp"
#include "../classes/Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
	Bureaucrat buro("ciuschi", 3);

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