#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed ( void ) : _raw(0) {	}
Fixed::Fixed ( const Fixed & other ) : _raw(other._raw) {	}
Fixed::Fixed ( const int int_value ) : _raw (int_value << Fixed::_fractional_bits) {	}
Fixed::Fixed ( const float float_value ) : _raw ((int)roundf(float_value * (1 << Fixed::_fractional_bits))) {	}

Fixed &	Fixed::operator= ( const Fixed & other ) {
	this->setRawBits(other.getRawBits());
	return *this;
}

std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed ) {
	return (output_stream << fixed.toFloat());
}

// comparison operators
bool	operator<	(const Fixed & left, const Fixed & right )	{ return (left.getRawBits() < right.getRawBits()); }
bool	operator>	(const Fixed & left, const Fixed & right )	{ return (left.getRawBits() > right.getRawBits()); }
bool	operator<=	(const Fixed & left, const Fixed & right )	{ return (left.getRawBits() <= right.getRawBits()); }
bool	operator>=	(const Fixed & left, const Fixed & right )	{ return (left.getRawBits() >= right.getRawBits()); }
bool	operator==	(const Fixed & left, const Fixed & right )	{ return (left.getRawBits() == right.getRawBits()); }
bool	operator!=	(const Fixed & left, const Fixed & right )	{ return (left.getRawBits() != right.getRawBits()); }

// arithmetic operators
Fixed operator+ ( Fixed left, const Fixed & right ) {
	left.setRawBits(left.getRawBits() + right.getRawBits());
	return (left);
}
Fixed operator- ( Fixed left, const Fixed & right ) {
	left.setRawBits(left.getRawBits() - right.getRawBits());
	return (left);
}
Fixed operator* ( Fixed left, const Fixed & right ) {
	left.setRawBits((int)roundf(left.toFloat() * right.toFloat() * (1 << Fixed::getFractionalBits())));
	return (left);
}
Fixed operator/ ( Fixed left, const Fixed & right ) {
	left.setRawBits((int)roundf(left.toFloat() / right.toFloat() * (1 << Fixed::getFractionalBits())));
	return (left);
}

// increament, decreament operators
Fixed &	Fixed::operator++ () {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}
Fixed	Fixed::operator++ ( int ) {
	Fixed	old(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (old);
}
Fixed &	Fixed::operator-- () {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}
Fixed	Fixed::operator-- ( int ) {
	Fixed	old(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (old);
}

Fixed::~Fixed ( void ) {	}

Fixed & Fixed::min	( Fixed & left, Fixed & right )				{ return (left > right ? right : left); }
Fixed & Fixed::min	( const Fixed & left, const Fixed & right )	{ return (Fixed &)(left > right ? right : left); }
Fixed & Fixed::max	( Fixed & left, Fixed & right )				{ return (left < right ? right : left); }
Fixed & Fixed::max	( const Fixed & left, const Fixed & right )	{ return (Fixed &)(left < right ? right : left); }

int		Fixed::getRawBits ( void ) const	{ return (this->_raw); }
void	Fixed::setRawBits ( int const raw )	{ this->_raw = raw; }
int		Fixed::getFractionalBits ( void )	{ return (Fixed::_fractional_bits); }

float	Fixed::toFloat( void ) const	{ return ((float)this->getRawBits() / (1 << Fixed::_fractional_bits)); }
int		Fixed::toInt( void ) const		{ return (this->getRawBits() >> Fixed::_fractional_bits); }
