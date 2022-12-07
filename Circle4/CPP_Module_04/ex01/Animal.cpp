#include <iostream>
#include "Animal.hpp"

Animal::Animal ( void )
{
	std::cout << GREEN << "[Animal] default constructor" << WHITE << std::endl;
}

Animal::Animal ( std::string type ) : type(type)
{
	std::cout << GREEN << "[Animal] type constructor" << WHITE << std::endl;
}

Animal::Animal ( const Animal & other ) : type(other.type)
{
	std::cout << GREEN << "[Animal] copy constructor" << WHITE << std::endl;
}

Animal::~Animal ( void )
{
	std::cout << RED << "[Animal] destructor" << WHITE << std::endl;
}

Animal &	Animal::operator= ( const Animal & other )
{
	this->type = other.type;
	return *this;
}

const std::string &	Animal::getType ( void ) const
{
	return (this->type);
}

void	Animal::makeSound ( void ) const
{
	std::cout << "동물동물" << std::endl;
}
