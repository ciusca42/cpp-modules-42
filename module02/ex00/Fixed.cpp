#include "Fixed.hpp"

Fixed::Fixed( void ): value(0) {
	std::cout << "Copy constructor called\n";
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