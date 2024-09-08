#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "../includes/interface.hpp" // IWYU pragma: keep

class AMateria {

	protected:
		std::string type;

	public:
		AMateria();
		AMateria(std::string const &type);
		~AMateria();
		AMateria(const AMateria &obj);
		AMateria & operator=(const AMateria &obj);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

};

#endif