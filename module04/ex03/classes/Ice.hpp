#ifndef ICE_HPP
# define ICE_HPP

#include "../includes/interface.hpp" // IWYU pragma: keep
#include "AMateria.hpp"
#include "ICharacter.hpp" // IWYU pragma: keep

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice &obj);
		Ice & operator=(const Ice &obj);

		std::string const & getType(void) const;

		void use(ICharacter &target) const;

		AMateria* clone(void) const;
	private:
		std::string type;

};

#endif