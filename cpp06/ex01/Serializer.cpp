#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default Constructor Called" << std::endl;
}

Serializer::Serializer( Serializer& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

Serializer& Serializer::operator=( const Serializer& obj) {
	(void)obj;
	return (*this);
}

uintptr_t Serializer::serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data *>(raw);
}

Serializer::~Serializer() {
	std::cout << "Deconstructor Called" << std::endl;
}

