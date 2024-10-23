#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
#include "colors.hpp"

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap( std::string name );
		~ClapTrap();
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired ( unsigned int amount );
		void setDmg (unsigned int amount );
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDmg;
		int maxHealth;
};

#endif