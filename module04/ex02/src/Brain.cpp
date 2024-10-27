#include "../classes/Brain.hpp"
#include "../includes/colors.hpp"
#include <cstdlib>
#include <iostream>

void debugPrint(std::string msg, int type);

Brain::Brain(void): nIdeas(0) {
	debugPrint("Brain", 0);
}

Brain::~Brain(void) {
	debugPrint("Brain", 1);
}

Brain::Brain(const Brain &obj) {
	*this = obj;
}

Brain & Brain::operator=(const Brain &obj) {
	int i = 0;

	while (!obj._ideas[i].empty()) {
		this->_ideas[i] = obj._ideas[i];
		i++;
	}
	return *this;
}

void Brain::setIdea(std::string idea) {
	if (nIdeas >= 100) {
		std::cerr << PINK400 << "The brain is full!\n" RESET;
		return ;
	}
	this->_ideas[nIdeas] = idea;
	this->nIdeas++;
}

void Brain::getRandomIdea(void) {
	if (nIdeas >= 100) {
		std::cerr << PINK400 << "The brain is full\n" RESET;
	}
	std::cout << CYAN300 << "idea: " << RESET << this->_ideas[random() % nIdeas] << '\n';
}
