#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() { 
	std::cout << "Default constructor called\n";
}

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Default destrucotr called\n";
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &obj) { 
	*this = obj;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &obj) {
	this->std::stack<T>(obj);
}

	template<typename T>
	typename MutantStack<T>::iterator MutantStack<T>::begin() {
		iterator first;

		first = std::stack<T>::c.begin();
		return first;
	}

	template<typename T>
	typename MutantStack<T>::iterator MutantStack<T>::end() {
		iterator first;

		first = this->std::stack<T>::c.end();
		return first;
	}

