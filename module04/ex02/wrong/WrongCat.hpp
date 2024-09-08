#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream> // IWYU pragma: keep

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat & obj);
		WrongCat & operator=(const WrongCat & obj);

		std::string getType(void) const;

		void makeSound(void) const;
	private:
		std::string _type;
};

#endif