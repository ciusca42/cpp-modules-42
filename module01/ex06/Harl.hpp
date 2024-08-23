#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include "colors.hpp"

class Harl {
	public:
		Harl();
		~Harl();
		void complain( std::string level );
	private:
		void debug ( void ) const;
		void info ( void ) const;
		void warning ( void ) const;
		void error ( void ) const;
};

#endif