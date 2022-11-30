#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wj = new WrongCat();
	std::cout << wj->getType() << " " << std::endl;
	wj->makeSound();
	wmeta->makeSound();

	delete (meta);
	delete (j);
	delete (i);
	delete (wmeta);
	delete (wj);
	return 0;
}
