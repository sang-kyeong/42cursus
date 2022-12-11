#ifndef __ITER_H__
# define __ITER_H__

template < typename T >
void	iter ( T * array, size_t length, void (* func)(const T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#include <iostream>

template < typename T >
void	ft_print ( const T & arg )
{
	std::cout << arg << ' ';
}

#endif//__ITER_H__
