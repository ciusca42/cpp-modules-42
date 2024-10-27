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
