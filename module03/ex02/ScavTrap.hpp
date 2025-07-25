#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap( void );
		ScavTrap(const ScavTrap &obj);
		ScavTrap & operator=(ScavTrap const &obj);
		
		void attack(const std::string &target);
		void guardGate(void);
	
};

#endif