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

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "<========================================================================>" << std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();
	const WrongCat *cat = new WrongCat();
	wrong->makeSound();
	wrongcat->makeSound();
	cat->makeSound();
	delete wrong;
	delete wrongcat;
	delete cat;

	// return 0;
	return (0);
}
