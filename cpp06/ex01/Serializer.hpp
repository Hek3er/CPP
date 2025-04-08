#pragma once

# include <iostream>

struct Data {
	int val;
};

class Serializer {

public:

	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer( Serializer& obj );
	Serializer& operator=( const Serializer& obj );

};