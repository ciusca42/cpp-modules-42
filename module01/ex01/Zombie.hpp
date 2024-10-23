#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		Zombie();
		~Zombie();
		void setName( std::string );
		void randomChump( std::string name );
		void announce ( void );
		Zombie *newZombie( std::string name );
	private:
		std::string	name;
};
		Zombie *zombieHorde ( int N, std::string name );


#endif