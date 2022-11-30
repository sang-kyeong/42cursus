#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat ( void ) : WrongAnimal("WrongCat")
{
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::WrongCat ( const WrongCat & other )
{
	this->type = other.type;
	std::cout << "Wrong Cat copy constructor called" << std::endl;
}

WrongCat::~WrongCat ( void )
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat &	WrongCat::operator= ( const WrongCat & other )
{
	this->type = other.type; return (*this);
}

void	WrongCat::makeSound ( void ) const
{
	std::cout << "멍멍" << std::endl;
}
