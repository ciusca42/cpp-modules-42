#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal & obj);
		Animal & operator=(const Animal & obj);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;
	protected:
		std::string type;
};

#endif