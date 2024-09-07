#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap( void );

		ScavTrap & operator=(ScavTrap const &obj);
		
		virtual void attack(const std::string &target);
		void guardGate(void);
	
};

#endif