#ifndef __EASYFIND_H__
# define __EASYFIND_H__

# include <algorithm>

template < typename C >
typename C::iterator easyfind ( C container, int target )
{
	return std::find(container.begin(), container.end(), target);
}

#endif//__EASY_FIND__
