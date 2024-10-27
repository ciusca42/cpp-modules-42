#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain &obj);
		Brain & operator=(const Brain &obj);

	private:
		int nIdeas;
		std::string _ideas[100];
};

#endif