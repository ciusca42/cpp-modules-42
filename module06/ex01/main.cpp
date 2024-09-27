#include "Serializer.hpp"

int main(void) {
	Data *data = new Data("ciuschi", 20, true);
	uintptr_t	serialized_data;

	Data *deserialized_data;
	serialized_data = Serializer::serialize(data);

	deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << "serialized cast: " << serialized_data << "\n";

	std::cout << "original data: " << data << "\ndeserialized data: " << deserialized_data << '\n';

	delete data;

}