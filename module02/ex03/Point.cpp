#include "Point.hpp"

Point::Point( void ): x(0), y(0) {}

Point::Point (const float x, const float y): x(x), y(y) {}

Point::~Point ( void ) {}

Fixed const Point::getX() const {
	return this->x;
}

Fixed const Point::getY() const {
	return this->y;
}

Point& Point::operator=(const Point &obj) {
		if (this != &obj)
			new (this)Point(obj.getX().toFloat(), obj.getY().toFloat());
	return *this;
}

Point::Point(const Point &obj) {
	*this = obj;
}

