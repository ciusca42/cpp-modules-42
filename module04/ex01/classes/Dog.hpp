#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog();
		~Dog();
		Dog(const Dog & obj);
		Dog & operator=(const Dog & obj);

		void makeSound(void) const;
	private:
		Brain*		_brain;
		std::string _type;
};

#endif