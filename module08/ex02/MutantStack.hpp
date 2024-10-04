#ifndef MOUTANTSTACK_HPP
# define MOUTANTSTACK_HPP

#include <stack>
#include <iostream> // IWYU pragma: keep


template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & obj);
		MutantStack<T> & operator=(const MutantStack<T> & obj);
		
		typedef	typename std::stack<T>::container_type::iterator	iterator;
		iterator end();
		iterator begin();
	
};

#include "MutantStack.tpp"

#endif