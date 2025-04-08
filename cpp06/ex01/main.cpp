#include "Serializer.hpp"

int main() {
	Data d;
	d.val = 42;

	std::cout << "d   Address = " << &d << std::endl;

	uintptr_t raw = Serializer::serialize(&d);

	std::cout << "raw Address = 0x" << std::hex << raw << std::endl;

	Data *np = Serializer::deserialize(raw);

	std::cout << "d.value = " << std::dec << d.val << " | np->val = " << np->val << std::endl;

	return (0);
}
