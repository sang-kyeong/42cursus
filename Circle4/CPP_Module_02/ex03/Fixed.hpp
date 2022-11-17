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

	// insertion operator
	friend std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed );

	// comparison operators
	friend bool	operator< (const Fixed & left, const Fixed & right );
	friend bool	operator> (const Fixed & left, const Fixed & right );
	friend bool	operator<= (const Fixed & left, const Fixed & right );
	friend bool	operator>= (const Fixed & left, const Fixed & right );
	friend bool	operator== (const Fixed & left, const Fixed & right );
	friend bool	operator!= (const Fixed & left, const Fixed & right );

	// arithmetic operators
	friend Fixed operator+ ( Fixed left, const Fixed & right );
	friend Fixed operator- ( Fixed left, const Fixed & right );
	friend Fixed operator* ( Fixed left, const Fixed & right );
	friend Fixed operator/ ( Fixed left, const Fixed & right );

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

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

#endif //__FIXED_H__
