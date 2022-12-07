#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal ( void )
{
	std::cout << GREEN << "[AAnimal] default constructor" << WHITE << std::endl;
}

AAnimal::AAnimal ( std::string type ) : type(type)
{
	std::cout << GREEN << "[AAnimal] type constructor" << WHITE << std::endl;
}

AAnimal::AAnimal ( const AAnimal & other ) : type(other.type)
{
	std::cout << GREEN << "[AAnimal] copy constructor" << WHITE << std::endl;
}

AAnimal::~AAnimal ( void )
{
	std::cout << RED << "[AAnimal] destructor" << WHITE << std::endl;
}

AAnimal &	AAnimal::operator= ( const AAnimal & other )
{
	this->type = other.type;
	return *this;
}

const std::string &	AAnimal::getType ( void ) const
{
	return (this->type);
}

void	AAnimal::makeSound ( void ) const
{
	std::cout << "동물동물" << std::endl;
}
