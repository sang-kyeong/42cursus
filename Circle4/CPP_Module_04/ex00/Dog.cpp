#include <iostream>
#include "Dog.hpp"

Dog::Dog ( void ) : Animal("Dog")
{
	std::cout << GREEN << "[Dog] default constructor" << WHITE << std::endl;
}

Dog::Dog ( const Dog & other ) : Animal(other)
{
	std::cout << GREEN << "[Dog] copy constructor" << WHITE << std::endl;
}

Dog::~Dog ( void )
{
	std::cout << RED << "[Dog] destructor" << WHITE << std::endl;
}

Dog &	Dog::operator= ( const Dog & other )
{
	Animal::operator=(other);
	return *this;
}

void	Dog::makeSound ( void ) const
{
	std::cout << "멍멍" << std::endl;
}
