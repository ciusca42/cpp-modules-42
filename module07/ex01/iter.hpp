#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> void iter(T *addr, int n, void(*func)(T par)) {
	for (int i = 0; i < n; i++) {
		func(addr[i]);
	}
}

template <typename T> void print(T base) {
	std::cout << base << '-';
}

#endif