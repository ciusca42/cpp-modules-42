#ifndef ICE_HPP
# define ICE_HPP

#include "../includes/interface.hpp" // IWYU pragma: keep
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice &obj);
		Ice & operator=(const Ice &obj);

		void use(ICharacter &target) const;

		AMateria* clone(void) const;

};

#endif