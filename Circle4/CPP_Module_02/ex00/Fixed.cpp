#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed ( void ) : _raw(0) {	}
Fixed::Fixed ( const Fixed & other ) : _raw(other._raw) {	}

Fixed &	Fixed::operator= ( const Fixed & other ) {
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed ( void ) {	}

int		Fixed::getRawBits ( void ) const	{ return (this->_raw); }
void	Fixed::setRawBits ( int const raw )	{ this->_raw = raw; }
