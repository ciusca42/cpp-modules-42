#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream> // IWYU pragma: keep
#include "../includes/colors.hpp" // IWYU pragma: keep

class WrongAnimal {
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal & obj);
		WrongAnimal & operator=(const WrongAnimal & obj);

		std::string getType(void) const;
		void setType(std::string type);

		void makeSound(void) const;
	protected:
		std::string _type;
};

#endif