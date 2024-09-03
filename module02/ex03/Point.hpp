#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point( const float x, const float y );
		Point(const Point & obj);
		~Point();

		Point & operator=(Point const &obj);

		Fixed const getX( void ) const;
		Fixed const getY( void ) const;
	private:
		Fixed const x;
		Fixed const y;

};

#endif