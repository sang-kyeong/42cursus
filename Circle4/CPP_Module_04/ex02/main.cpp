#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		//const AAnimal meta = AAnimal();
		const AAnimal * j = new Dog();
		const AAnimal * i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound(); //will output the cat sound!
		//meta->makeSound();

		delete i;
		delete j;
	}
	system("leaks ex02 | grep total");
	return 0;
}
