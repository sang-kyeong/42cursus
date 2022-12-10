#ifndef __ITER_H__
# define __ITER_H__

template < typename T >
void	iter ( T * array, size_t length, void (* func)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#include <iostream>

template < typename T >
void	print ( T & arg )
{
	std::cout << arg << ' ';
}

#endif//__ITER_H__
