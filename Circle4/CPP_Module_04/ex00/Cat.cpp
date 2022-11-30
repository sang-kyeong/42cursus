#include <iostream>
#include "Cat.hpp"

Cat::Cat ( void ) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat ( const Cat & other )
{
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat ( void )
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &	Cat::operator= ( const Cat & other )
{
	this->type = other.type; return (*this);
}

void	Cat::makeSound ( void ) const
{
	std::cout << "콐ㅋ콐콐ㅋㅋㅋ콐켸ㅖㅖㅋ콐ㅋ" << std::endl;
}
