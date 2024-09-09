#ifndef CURE_HPP
# define CURE_HPP

#include "../includes/interface.hpp" // IWYU pragma: keep
#include "AMateria.hpp"
#include "ICharacter.hpp" // IWYU pragma: keep

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure &obj);
		Cure & operator=(const Cure &obj);

		std::string const & getType(void) const;

		void use(ICharacter &target) const;

		AMateria* clone(void) const;
	
	private:
		std::string type;

};

#endif