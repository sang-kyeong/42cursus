#include <iostream>
#include "Cat.hpp"

Cat::Cat ( void ) : Animal("Cat")
{
	std::cout << GREEN << "[Cat] default constructor" << WHITE << std::endl;
}

Cat::Cat ( const Cat & other ) : Animal(other)
{
	std::cout << GREEN << "[Cat] copy constructor" << WHITE << std::endl;
}

Cat::~Cat ( void )
{
	std::cout << RED << "[Cat] destructor" << WHITE << std::endl;
}

Cat &	Cat::operator= ( const Cat & other )
{
	Animal::operator=(other);
	return *this;
}

void	Cat::makeSound ( void ) const
{
	std::cout << "야옹" << std::endl;
}
