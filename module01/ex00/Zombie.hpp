#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		Zombie();
		~Zombie();
		Zombie & operator=(const Zombie & obj);
		void randomChump( std::string name );
		Zombie *newZombie( std::string name );
		void setName(std::string name);
		void announce ( void );

	private:
		std::string	name;
};

#endif