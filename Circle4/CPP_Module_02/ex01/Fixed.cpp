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

Fixed::Fixed ( const int int_value ) : _raw (int_value << Fixed::_fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed ( const float float_value ) : _raw ((int)roundf(float_value * (1 << Fixed::_fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &	Fixed::operator= ( const Fixed & other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = other.getRawBits();
	return *this;
}

std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed ) {
	return (output_stream << fixed.toFloat());
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits ( void ) const	{ return (this->_raw); }
void	Fixed::setRawBits ( int const raw )	{ this->_raw = raw; }

float	Fixed::toFloat( void ) const	{ return ((float)this->getRawBits() / (1 << Fixed::_fractional_bits)); }
int		Fixed::toInt( void ) const		{ return (this->getRawBits() >> Fixed::_fractional_bits); }
