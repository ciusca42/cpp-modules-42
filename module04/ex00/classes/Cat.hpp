#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		~Cat();
		Cat(const Cat & obj);
		Cat & operator=(const Cat & obj);

		void makeSound(void) const;
	private:
		std::string type;
};

#endif