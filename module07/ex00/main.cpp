#include "whatever.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;

	std::cout << "Before Swap\n";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	::swap( a, b );
	
	std::cout << "After Swap\n";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "Before Swap\n";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	
	::swap(c, d);
	
	std::cout << "After Swap\n";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}