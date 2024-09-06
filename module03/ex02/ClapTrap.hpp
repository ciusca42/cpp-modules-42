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
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired ( unsigned int amount );
		void diePrint(void);
		void noEnergy(void);
		/* getter and setter */
		std::string getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDmg(void) const;

		void		setName(std::string name);
		void		setHitPoints(unsigned int amount);
		void		setEnergyPoints(unsigned int amount);
		void 		setAtkDmg (unsigned int amount );
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDmg;
};

#endif