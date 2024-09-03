#include "Point.hpp"

float crossProduct(Point a, Point b, Point p) { 
	// vector AB
	Point ab(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point ap(p.getX().toFloat() - a.getX().toFloat(), p.getY().toFloat() - a.getY().toFloat());

	return (ab.getX().toFloat() * ap.getY().toFloat()) - (ab.getY().toFloat() * ap.getX().toFloat());
}

bool bsp(Point a, Point b, Point c, Point p) {
	float ap = crossProduct(a, b, p);
	float bp = crossProduct(b, c, p);
	float cp = crossProduct(c, a, p);

	if ((ap > 0 && bp > 0 && cp > 0) || (ap < 0 && bp < 0 && cp < 0))
		return true;
	return false;
}