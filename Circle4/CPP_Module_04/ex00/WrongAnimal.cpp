#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal ( void )
{
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( std::string type ) : type(type)
{
	std::cout << "Wrong Animal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( const WrongAnimal & other ) : type(other.type)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal ( void )
{
	std::cout << "Animal destructor called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator= ( const WrongAnimal & other )
{
	this->type = other.type;
	return (*this);
}

const std::string &	WrongAnimal::getType ( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound ( void ) const
{
	std::cout << "야옹" << std::endl;
}
