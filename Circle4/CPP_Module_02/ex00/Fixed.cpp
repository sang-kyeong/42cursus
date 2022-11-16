#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed ( const Fixed & other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &	Fixed::operator= ( const Fixed & other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits ( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}
