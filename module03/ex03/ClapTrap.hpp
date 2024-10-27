#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
#include "colors.hpp"

class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap();
		ClapTrap(const ClapTrap &obj);
		ClapTrap &operator=(const ClapTrap &obj);

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired ( unsigned int amount );
		void diePrint(void);
		void noEnergy(void);
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDmg;
		int maxHealth;
};

#endif