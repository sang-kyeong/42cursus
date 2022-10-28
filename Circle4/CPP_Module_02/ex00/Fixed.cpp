#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed	( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed	( const Fixed &fixed_point_number )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed_point_number;
}

Fixed & Fixed::operator = ( const Fixed &fixed_point_number )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed_point_number.getRawBits());
	return (*this);
}

Fixed::~Fixed	( void )
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits ( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
