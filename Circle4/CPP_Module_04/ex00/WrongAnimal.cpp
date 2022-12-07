#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal ( void )
{
	std::cout << GREEN << "[WrongAnimal] default constructor" << WHITE << std::endl;
}

WrongAnimal::WrongAnimal ( std::string type ) : type(type)
{
	std::cout << GREEN << "[WrongAnimal] type constructor" << WHITE << std::endl;
}

WrongAnimal::WrongAnimal ( const WrongAnimal & other ) : type(other.type)
{
	std::cout << GREEN << "[WrongAnimal] copy constructor" << WHITE << std::endl;
}

WrongAnimal::~WrongAnimal ( void )
{
	std::cout << RED << "[WrongAnimal] destructor" << WHITE << std::endl;
}

WrongAnimal &	WrongAnimal::operator= ( const WrongAnimal & other )
{
	this->type = other.type;
	return *this;
}

const std::string &	WrongAnimal::getType ( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound ( void ) const
{
	std::cout << "동물동물" << std::endl;
}
