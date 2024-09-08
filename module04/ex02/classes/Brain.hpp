#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain &obj);
		Brain & operator=(const Brain &obj);

		void setIdea(std::string idea);
		void getRandomIdea(void);

	private:
		int nIdeas;
		std::string _ideas[100];
};

#endif