#include <iostream>
#include "Cat.hpp"

Cat::Cat ( void ) : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << GREEN << "[Cat] default constructor" << WHITE << std::endl;
}

Cat::Cat ( const Cat & other ) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << GREEN << "[Cat] copy constructor" << WHITE << std::endl;
}

Cat::~Cat ( void )
{
	delete this->_brain;
	std::cout << RED << "[Cat] destructor" << WHITE << std::endl;
}

Cat &	Cat::operator= ( const Cat & other )
{
	AAnimal::operator=(other);
	*(this->_brain) = *(other._brain);
	return *this;
}

void	Cat::makeSound ( void ) const
{
	std::cout << "야옹" << std::endl;
}
