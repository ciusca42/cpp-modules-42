#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed( const int num );
		Fixed( const float num );
		~Fixed();
		Fixed(const Fixed & obj);
		Fixed& operator=(const Fixed & obj);
		Fixed& operator<<(const Fixed &obj);
		int getRawBits( void ) const;
		float toFloat( void ) const;
		int toInt ( void ) const;
		void setRawBits (int const raw );
	private:
		int 		value;
		static const int	bits = 8;
};

#endif