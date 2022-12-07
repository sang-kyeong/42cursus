#include <iostream>
#include "Dog.hpp"

Dog::Dog ( void ) : Animal("Dog"), _brain(new Brain())
{
	std::cout << GREEN << "[Dog] default constructor" << WHITE << std::endl;
}

Dog::Dog ( const Dog & other ) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << GREEN << "[Dog] copy constructor" << WHITE << std::endl;
}

Dog::~Dog ( void )
{
	delete this->_brain;
	std::cout << RED << "[Dog] destructor" << WHITE << std::endl;
}

Dog &	Dog::operator= ( const Dog & other )
{
	Animal::operator=(other);
	*(this->_brain) = *(other._brain);
	return *this;
}

void	Dog::makeSound ( void ) const
{
	std::cout << "멍멍" << std::endl;
}
