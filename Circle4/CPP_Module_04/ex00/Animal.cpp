#include <iostream>
#include "Animal.hpp"

Animal::Animal ( void )
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal ( std::string type ) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal ( const Animal & other ) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal ( void )
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &	Animal::operator= ( const Animal & other )
{
	this->type = other.type;
	return (*this);
}

const std::string &	Animal::getType ( void ) const
{
	return (this->type);
}

void	Animal::makeSound ( void ) const
{
	std::cout << "야옹" << std::endl;
}
