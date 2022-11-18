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

Fixed::~Fixed ( void ) {	}

int		Fixed::getRawBits ( void ) const	{ return (this->_raw); }
void	Fixed::setRawBits ( int const raw )	{ this->_raw = raw; }

float	Fixed::toFloat( void ) const	{ return ((float)this->getRawBits() / (1 << Fixed::_fractional_bits)); }
int		Fixed::toInt( void ) const		{ return (this->getRawBits() >> Fixed::_fractional_bits); }
