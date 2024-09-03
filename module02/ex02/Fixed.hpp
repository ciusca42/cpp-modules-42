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
		Fixed operator+(const Fixed & obj);
		Fixed operator-(const Fixed & obj);
		Fixed operator*(const Fixed & obj);
		Fixed operator/(const Fixed & obj);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		bool operator>(const Fixed & obj);
		bool operator<(const Fixed & obj);
		bool operator>=(const Fixed & obj);
		bool operator<=(const Fixed & obj);
		bool operator==(const Fixed & obj);
		bool operator!=(const Fixed & obj);

		int getRawBits( void ) const;
		float toFloat( void ) const;
		int toInt ( void ) const;
		void setRawBits (int const raw );

		static Fixed& min(Fixed &num1, Fixed &num2); 
		static Fixed const & min(const Fixed &num1, const Fixed &num2);
		static Fixed& max(Fixed &num1, Fixed &num2); 
		static Fixed const & max(const Fixed &num1, const Fixed &num2);

	private:
		int 		value;
		static const int	bits = 8;
};

std::ostream& operator<<(std::ostream& stream, Fixed const &obj);

#endif