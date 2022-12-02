#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed ( void ) : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed & other )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_raw = other.getRawBits();
}

Fixed &	Fixed::operator= ( const Fixed & other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = other.getRawBits();
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
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}
