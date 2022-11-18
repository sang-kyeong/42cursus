#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	// std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed ( const Fixed & other )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed ( const int int_value )
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits ( int_value << this->_fractional_bits );
}

Fixed::Fixed ( const float float_value )
{
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_value * (1 << this->_fractional_bits)));
}

Fixed &	Fixed::operator= ( const Fixed & other )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed )
{
	output_stream << fixed.toFloat();
	return (output_stream);
}

// comparison operators
bool	operator< (const Fixed & left, const Fixed & right )
{
	return (left.getRawBits() < right.getRawBits());
}

bool	operator> (const Fixed & left, const Fixed & right )
{
	return (left.getRawBits() > right.getRawBits());
}

bool	operator<= (const Fixed & left, const Fixed & right )
{
	return (left.getRawBits() <= right.getRawBits());
}

bool	operator>= (const Fixed & left, const Fixed & right )
{
	return (left.getRawBits() >= right.getRawBits());
}

bool	operator== (const Fixed & left, const Fixed & right )
{
	return (left.getRawBits() == right.getRawBits());
}

bool	operator!= (const Fixed & left, const Fixed & right )
{
	return (left.getRawBits() != right.getRawBits());
}

// arithmetic operators
Fixed operator+ ( Fixed left, const Fixed & right )
{
	left.setRawBits(left.getRawBits() + right.getRawBits());
	return (left);
}

Fixed operator- ( Fixed left, const Fixed & right )
{
	left.setRawBits(left.getRawBits() - right.getRawBits());
	return (left);
}

Fixed operator* ( Fixed left, const Fixed & right )
{
	left.setRawBits((int)roundf(left.toFloat() * right.toFloat() * (1 << Fixed::getFractionalBits())));
	return (left);
}

Fixed operator/ ( Fixed left, const Fixed & right )
{
	left.setRawBits((int)roundf(left.toFloat() / right.toFloat() * (1 << Fixed::getFractionalBits())));
	return (left);
}

// increament, decreament operators
Fixed &	Fixed::operator++ ()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++ ( int )
{
	Fixed	old = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (old);
}

Fixed &	Fixed::operator-- ()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator-- ( int )
{
	Fixed	old = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (old);
}

Fixed::~Fixed ( void )
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::min ( Fixed & left, Fixed & right )
{
	return (left > right ? right : left);
}

Fixed & Fixed::min ( const Fixed & left, const Fixed & right )
{
	return (Fixed &)(left > right ? right : left);
}

Fixed & Fixed::max ( Fixed & left, Fixed & right )
{
	return (left < right ? right : left);
}

Fixed & Fixed::max ( const Fixed & left, const Fixed & right )
{
	return (Fixed &)(left < right ? right : left);
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

int		Fixed::getFractionalBits ( void )
{
	return (Fixed::_fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	// std::cout << "toFloat member function called" << std::endl;
	return ((float)this->getRawBits() / (1 << Fixed::getFractionalBits()));
}

int		Fixed::toInt( void ) const
{
	// std::cout << "toInt member function called" << std::endl;
	return (this->getRawBits() >> Fixed::getFractionalBits());
}
