#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed
{

private:

	int					_value;
	static const int	_fractional_bit = 8;

public:

	Fixed	( void );
	Fixed	( const Fixed &fixed_point_number );

	Fixed& operator= ( const Fixed &fixed_point_number );

	~Fixed	( void );

	int		getRawBits ( void ) const;
	void	setRawBits ( int const raw );

};

#endif //__FIXED_H__