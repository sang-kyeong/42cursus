#ifndef __FIXED_H__
# define __FIXED_H__

#include <ostream>

class Fixed
{

private:

	int					_raw;
	static const int	_fractional_bits = 8;

public:

	// constructors
	Fixed ( void );
	Fixed ( const Fixed & other );
	Fixed ( const int int_value );
	Fixed ( const float float_value );

	// copy operator
	Fixed &	operator= ( const Fixed & other );

	// increament, decreament operators
	Fixed &	operator++ ();
	Fixed	operator++ ( int );
	Fixed &	operator-- ();
	Fixed	operator-- ( int );

	// destructor
	~Fixed ( void );

	// Min Max functions
	static Fixed & min ( Fixed & fixed1, Fixed & fixed2 );
	static Fixed & min ( const Fixed & fixed1, const Fixed & fixed2 );
	static Fixed & max ( Fixed & fixed1, Fixed & fixed2 );
	static Fixed & max ( const Fixed & fixed1, const Fixed & fixed2 );

	// getter, setter
	int		getRawBits ( void ) const;
	void	setRawBits ( int const raw );
	static int		getFractionalBits ( void );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

// insertion operator
std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed );

// comparison operators
bool	operator< (const Fixed & left, const Fixed & right );
bool	operator> (const Fixed & left, const Fixed & right );
bool	operator<= (const Fixed & left, const Fixed & right );
bool	operator>= (const Fixed & left, const Fixed & right );
bool	operator== (const Fixed & left, const Fixed & right );
bool	operator!= (const Fixed & left, const Fixed & right );

// arithmetic operators
Fixed operator+ ( Fixed left, const Fixed & right );
Fixed operator- ( Fixed left, const Fixed & right );
Fixed operator* ( Fixed left, const Fixed & right );
Fixed operator/ ( Fixed left, const Fixed & right );

#endif //__FIXED_H__
