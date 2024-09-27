#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef> // IWYU pragma: keep
#include <exception>
#include <sys/types.h>



template <typename T>
class Array {
	public:
		Array();
		Array(uint n);
		~Array();
		Array(const Array & obj);
		Array & operator=(const Array & obj);

		unsigned int size() const;

		T &operator[](int i);
		T operator[](int i) const;

		class OutOfBounds: public std::exception {
			const char *what() const throw();
		};
	private:
		uint	len;
		T		*arr;
};

#include "Array.tpp"


#endif