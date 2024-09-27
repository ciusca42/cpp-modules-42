#include "classes/A.hpp"
#include "classes/B.hpp"
#include "classes/C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>


void identify(Base *p) {

	if (dynamic_cast<A*>(p))
		std::cout << "the pointer is type: A\n";	
	else if (dynamic_cast<B*>(p))
		std::cout << "the pointer is type: B\n";	
	else if (dynamic_cast<C*>(p))
		std::cout << "the pointer is type: C\n";
	else
		std::cerr << "Invalid pointer\n";
}
void identify(Base &p) {
	
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "the reference is type: A\n";

	} catch (std::exception & exc) {}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "the reference is type: B\n";

	} catch (std::exception & exc) {}

	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "the reference is type: C\n";

	} catch (std::exception & exc) {}
}

Base *generate(void) {
	int num = rand() % 3;
	char classCeated[3] = {'A', 'B', 'C'};

	std::cout << "Created the: " << classCeated[num] << " Class\n";
	switch (num) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return NULL;
}

int main(void) {
	Base *gen;

	srand(time(0));

	for (int i = 0; i < 5; i++) {
		gen = generate();
		identify(gen);
		identify(*gen);
		std::cout << '\n';
	}
}