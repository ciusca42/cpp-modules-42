#include "Fixed.hpp"

Fixed::Fixed( void ): value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	this->value = num << bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	this->value = roundf(num * (1 << bits));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed & obj) {
	std::cout << "Copy assignment operator called\n";
	this->value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits ( void ) const {
	std::cout << "getRawBits member function called\n";
	return this->value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	this->value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->value / (float)(1 << bits);
}

int Fixed::toInt ( void ) const {
	return this->value >> bits;
}

std::ostream&	operator<<(std::ostream& stream, Fixed const &obj) {
	stream << obj.toFloat();
	return stream;
}
