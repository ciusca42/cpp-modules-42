#include "Serializer.hpp"

Serializer::Serializer(void) {
	std::cout << "serializer constructor called\n";
}

Serializer::~Serializer(void) {
	std::cout << "serializer destructor called\n";
}

Serializer::Serializer(const Serializer &obj) {
	*this = obj;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}