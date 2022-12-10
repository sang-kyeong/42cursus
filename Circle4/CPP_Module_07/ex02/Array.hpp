#ifndef __ARRAY_H__
# define __ARRAY_H__

template < typename T >
class	Array
{

private:
	T				*_data;
	unsigned int	_size;

protected:

public:

	Array ( void );
	Array ( unsigned int n );
	Array ( const Array & other );
	~Array ( void );

	Array &	operator= ( const Array & other );
	T & operator[] ( const int	index ) const;

	unsigned int	size ( void ) const;

};

# include "Array.tpp"

#endif//__ARRAY_H__
