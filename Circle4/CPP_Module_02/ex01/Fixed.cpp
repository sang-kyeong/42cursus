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


Fixed::Fixed	( const int int_value )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(int_value << this->_fractional_bit);
}

Fixed::Fixed	( const float float_value )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(float_value * (1 << this->_fractional_bit));
}

Fixed & Fixed::operator = ( const Fixed &fixed_point_number )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed_point_number.getRawBits());
	return (*this);
}

std::ostream & operator << (std::ostream & output_stream, const Fixed & fixed_point_number)
{
	output_stream << (fixed_point_number.getRawBits() >> 8);
	if (fixed_point_number.getRawBits() & 0x00FF)
		output_stream << fixed_point_number.toFloat();
	else
		output_stream << fixed_point_number.toInt();
	return (output_stream);
}

Fixed::~Fixed	( void )
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits ( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat ( void ) const
{
	return (0);
}

int		Fixed::toInt ( void ) const
{
	unsigned int	value = (unsigned int)this->getRawBits();
	return (value >> this->_fractional_bit);
}