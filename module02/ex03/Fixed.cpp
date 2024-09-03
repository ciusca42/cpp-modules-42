#include "Fixed.hpp"

Fixed::Fixed( void ): value(0) {}

Fixed::Fixed(const int num) {
	
	this->value = num << bits;
}

Fixed::Fixed(const float num) {
	
	this->value = roundf(num * (1 << bits));
}

Fixed::~Fixed( void ) {}
	

Fixed::Fixed(const Fixed &obj) {
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed & obj) {
	this->value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits ( void ) const {
	return this->value;
}

void Fixed::setRawBits( int const raw ) {
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

Fixed Fixed::operator+(const Fixed &obj) {
	return this->toFloat() + obj.toFloat();
}

Fixed Fixed::operator-(const Fixed &obj) {
	return this->toFloat() - obj.toFloat();
}

Fixed Fixed::operator*(const Fixed &obj) {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) {
	return this->toFloat() / obj.toFloat();
}

bool Fixed::operator>(const Fixed &obj) {
	return this->value > obj.value;
}

bool Fixed::operator<(const Fixed &obj) {
	return this->value < obj.value;
}

bool Fixed::operator>=(const Fixed &obj) {
	return this->value >= obj.value;
}

bool Fixed::operator<=(const Fixed &obj) {
	return this->value <= obj.value;
}

bool Fixed::operator==(const Fixed &obj) {
	return this->value == obj.value;
}

bool Fixed::operator!=(const Fixed &obj) {
	return this->value != obj.value;
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2) {
	if (num1.value > num2.value)
		return num1;
	return num2;
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2) {
	if (num1.value > num2.value)
		return num1;
	return num2;
}

Fixed const & Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1.value < num2.value)
		return num1;
	return num2;
}

Fixed const & Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1.value > num2.value)
		return num1;
	return num2;
}

Fixed&	Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	operator--();
	return tmp;
}