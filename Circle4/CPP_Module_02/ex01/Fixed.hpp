#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>

class Fixed
{

private:

	int					_value;
	static const int	_fractional_bit = 8;

public:

	Fixed	( void );
	Fixed	( const Fixed &fixed_point_number );
	Fixed	( const int int_value );
	Fixed	( const float float_value );

	Fixed & operator = ( const Fixed &fixed_point_number );
	friend std::ostream & operator << (std::ostream & output_stream, const Fixed & fixed_point_number);

	~Fixed	( void );

	int		getRawBits ( void ) const;
	void	setRawBits ( int const raw );

	float	toFloat ( void ) const;
	int		toInt ( void ) const;

};

#endif //__FIXED_H__