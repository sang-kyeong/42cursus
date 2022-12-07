#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat ( void ) : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "[WrongCat] default constructor" << WHITE << std::endl;
}

WrongCat::WrongCat ( const WrongCat & other ) : WrongAnimal(other)
{
	std::cout << GREEN << "[WrongCat] copy constructor" << WHITE << std::endl;
}

WrongCat::~WrongCat ( void )
{
	std::cout << RED << "[WrongCat] destructor" << WHITE << std::endl;
}

WrongCat &	WrongCat::operator= ( const WrongCat & other )
{
	WrongAnimal::operator=(other);
	return *this;
}

void	WrongCat::makeSound ( void ) const
{
	std::cout << "야옹" << std::endl;
}
