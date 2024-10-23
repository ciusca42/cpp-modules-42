#include "Span.hpp"


Span::Span(uint N): _arr(0), _maxSize(N) {}

Span::~Span() {};

Span::Span(const Span &obj) {
	*this = obj;
}

Span &Span::operator=(const Span &obj) { 
	if (this == &obj)
		return *this;
	this->_arr = obj._arr;
	return *this;
}

void Span::addNumber(uint n) {
	if (this->_arr.size() +1 > _maxSize) { 
		std::cout << "maximum limit reached\n";
		return ;
	}
	this->_arr.push_back(n);
}

uint Span::longestSpan(void) {
	if (this->_arr.size() <= 1)
		throw NotEnoughNumbers();
	std::sort(this->_arr.begin(), this->_arr.end());

	return this->_arr[this->_arr.size() - 1] - this->_arr[0];
}

uint Span::shortestSpan() {
	uint	span = UINT_MAX;
	uint	diff;
	if (this->_arr.size() <= 1)
		throw NotEnoughNumbers();
	std::sort(this->_arr.begin(), this->_arr.end());
	for (size_t i = 0; i < this->_arr.size() - 1; i++) {
		diff = this->_arr[i + 1] - this->_arr[i];
		if (diff < span)
			span = diff; 
	}
	return span;
}

void Span::addRange(uint first, uint last) {
	std::vector<int> range;
	if (last - first + this->_arr.size() > this->_maxSize) {
		std::cout << "maximum limit reached\n";
		return ;
	}
	for (uint i = first; i < last; i++)
		range.push_back(i);
	this->_arr.insert(this->_arr.end(), range.begin(), range.end());
}

const char *Span::NotEnoughNumbers::what() const throw() {
	return "not enough numbers in the array\n";
}

void Span::print() {
	for (uint i = 0; i < this->_arr.size(); i++) {
		std::cout << this->_arr[i] << '\n';
	}
}
