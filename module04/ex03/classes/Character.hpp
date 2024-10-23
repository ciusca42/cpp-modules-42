#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter {
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character &obj);
		Character & operator=(const Character &obj);

		std::string const & getName(void) const;

		void equip(AMateria* m);
		AMateria *saveMateria(int idx);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		int			_nbMateria;
		std::string	_name;
		AMateria	*_inventory[4];
		void initInventory(void);
};

#endif