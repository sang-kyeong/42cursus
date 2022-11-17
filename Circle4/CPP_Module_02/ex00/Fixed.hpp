#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed
{

private:

	int					_raw;
	static const int	_fractional_bits = 8;

public:

	Fixed ( void );
	Fixed ( const Fixed & other );

	Fixed &	operator= ( const Fixed & other );

	~Fixed ( void );

	int		getRawBits ( void ) const;
	void	setRawBits ( int const raw );

};

#endif //__FIXED_H__
