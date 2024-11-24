#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	f() {
	system("leaks main");
}

int main() {

	atexit(f);

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	int size = 10;

	Animal *arr[size];
	for (int i = 0; i < size; i++) {
		if (i < size/2) {
			arr[i] = new Dog();
		} else {
			arr[i] = new Cat();
		}
	}


	for (int i = 0; i < size; i++) {
		arr[i]->makeSound();
	}

	for (int i = 0; i < size; i++) {
		delete arr[i];
	}

	return 0;
}
