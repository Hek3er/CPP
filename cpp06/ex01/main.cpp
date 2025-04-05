#include "Serializer.hpp"
#include <stdio.h>
#include <stdint.h>

int main() {
	Data d;
	d.val = 42;
	uintptr_t raw = Serializer::serialize(&d);
	Data *np = Serializer::deserialize(raw);
	std::cout << "d.val = " << d.val << " np->val = " << np->val << std::endl;
	std::cout << "raw = 0x" << std::hex << raw << std::endl;
	std::cout << "d = " << &d << std::endl;
	return (0);
}
