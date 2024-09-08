#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat();
		~Cat();
		Cat(const Cat & obj);
		Cat & operator=(const Cat & obj);

		void makeSound(void) const;
	private:
		Brain*		_brain;
		std::string type;
};

#endif