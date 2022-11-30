#include <iostream>
#include "Dog.hpp"

Dog::Dog ( void ) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog ( const Dog & other )
{
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog ( void )
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &	Dog::operator= ( const Dog & other )
{
	this->type = other.type; return (*this);
}

void	Dog::makeSound ( void ) const
{
	std::cout << "멍멍" << std::endl;
}
