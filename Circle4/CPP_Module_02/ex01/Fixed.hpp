#ifndef __FIXED_H__
# define __FIXED_H__

#include <ostream>

class Fixed
{

private:

	int					_raw;
	static const int	_fractional_bits = 8;

public:

	Fixed ( void );
	Fixed ( const Fixed & other );
	Fixed ( const int int_value );
	Fixed ( const float float_value );

	Fixed &	operator= ( const Fixed & other );
	friend std::ostream & operator<< ( std::ostream & output_stream, const Fixed & fixed );

	~Fixed ( void );

	int		getRawBits ( void ) const;
	void	setRawBits ( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

#endif //__FIXED_H__
