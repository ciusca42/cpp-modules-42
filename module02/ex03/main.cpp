#include "Point.hpp"	

bool bsp(Point a, Point b, Point c, Point p);

int main( void ) {

	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point p(2, 2);

	if (bsp(a, b, c, p) == true) {
		std::cout << "The Point is inside the triangle!\n";
		return (0);
	}
	std::cout << "The Point is outside the triangle!\n";
	return (1);
}