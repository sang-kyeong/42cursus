#include <iostream>
#include "WrongDog.hpp"

WrongDog::WrongDog ( void ) : WrongAnimal("WrongDog")
{
	std::cout << GREEN << "[WrongDog] default constructor" << WHITE << std::endl;
}

WrongDog::WrongDog ( const WrongDog & other ) : WrongAnimal(other)
{
	std::cout << GREEN << "[WrongDog] copy constructor" << WHITE << std::endl;
}

WrongDog::~WrongDog ( void )
{
	std::cout << RED << "[WrongDog] destructor" << WHITE << std::endl;
}

WrongDog &	WrongDog::operator= ( const WrongDog & other )
{
	WrongAnimal::operator=(other);
	return *this;
}

void	WrongDog::makeSound ( void ) const
{
	std::cout << "멍멍" << std::endl;
}
