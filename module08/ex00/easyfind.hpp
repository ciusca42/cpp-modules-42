#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream> // IWYU pragma: keep

template <typename T>
typename T::iterator easyfind(T &arr, int par) {
	return std::find(arr.begin(), arr.end(), par);
}

#endif