#include <iostream>
#include "MutantStack.hpp"
#include "Color.hpp"

template < class T, class C >
MutantStack<T, C>::MutantStack ( void ) : std::stack<T, C>()
{
	std::cout << BLACK << "[MutantStack] default constructor" << NORMAL << std::endl;
}

template < class T, class C >
MutantStack<T, C>::MutantStack ( const MutantStack & other ) : std::stack<T, C>(other)
{
	std::cout << BLACK << "[MutantStack] copy constructor" << NORMAL << std::endl;
}

template < class T, class C >
MutantStack<T, C>::~MutantStack ( void )
{
	std::cout << BLACK << "[MutantStack] destructor" << NORMAL << std::endl;
}

template < class T, class C >
MutantStack<T, C> &	MutantStack<T, C>::operator= ( const MutantStack & other )
{
	std::stack<T, C>::operator= (other);
	return *this;
}

template < class T, class C >
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin ( void )
{
	return this->c.begin();
}

template < class T, class C >
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end ( void )
{
	return this->c.end();
}

template < class T, class C >
typename MutantStack<T, C>::iterator	MutantStack<T, C>::rbegin ( void )
{
	return this->c.rbegin();
}

template < class T, class C >
typename MutantStack<T, C>::iterator	MutantStack<T, C>::rend ( void )
{
	return this->c.rend();
}
