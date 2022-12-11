#ifndef __EASYFIND_H__
# define __EASYFIND_H__

# include <exception>
# include <algorithm>

template < typename C >
typename C::iterator easyfind ( C container, int target )
{
	typename C::iterator	iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end())
		throw std::exception();
	return iter;
}

#endif//__EASY_FIND__
