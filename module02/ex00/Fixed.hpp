#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> // IWYU pragma: keep

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed & obj);
		Fixed& operator=(const Fixed & obj);
		int getRawBits( void ) const;
		void setRawBits (int const raw );
	private:
		int 		value;
		static const int	bits = 8;
};

#endif