#include <iostream>
#include <cmath>
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


Fixed::Fixed ( const int int_value )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits ( int_value << this->_fractional_bits );
}

Fixed::Fixed ( const float float_value )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_value * (1 << this->_fractional_bits)));
}

Fixed &	Fixed::operator= ( const Fixed & other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed )
{
	output_stream << fixed.toFloat();
	return (output_stream);
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits ( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

float	Fixed::toFloat( void ) const
{
	// std::cout << "toFloat member function called" << std::endl;
	return ((float)this->getRawBits() / (1 << this->_fractional_bits));
}

int		Fixed::toInt( void ) const
{
	// std::cout << "toInt member function called" << std::endl;
	return (this->getRawBits() >> this->_fractional_bits);
}