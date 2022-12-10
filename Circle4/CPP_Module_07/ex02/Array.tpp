#include <exception>
#include "Array.hpp"
#include "Color.hpp"

template < typename T >
Array<T>::Array ( void ) : _data(NULL), _size(0)
{
	std::cout << BLACK << "[Array] default constructor" << NORMAL << std::endl;
}

template < typename T >
Array<T>::Array ( unsigned int n ) : _data(NULL), _size(n)
{
	if (n != 0)
		this->_data = new T[n];
	std::cout << BLACK << "[Array] n constructor" << NORMAL << std::endl;
}

template < typename T >
Array<T>::Array ( const Array & other ) : _size(other._size)
{
	std::cout << BLACK << "[Array] copy constructor" << NORMAL << std::endl;
	if (this->_size == 0)
		this->_data = NULL;
	else
	{
		this->_data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			(*this)[i] = other[i];
	}
}

template < typename T >
Array<T>::~Array ( void )
{
	std::cout << BLACK << "[Array] destructor" << NORMAL << std::endl;
	if (this->_data != NULL)
		delete[] this->_data;
}

template < typename T >
Array<T> &	Array<T>::operator= ( const Array & other )
{
	if (this == *other)
		return *this;

	if (this->_data != NULL)
		delete[] this->_data;
	this->_size = other._size;

	if (this->_size == 0)
		this->_data = NULL;
	else
	{
		this->_data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			(*this)[i] = other[i];
	}
	return *this;
}

template < typename T >
T & Array<T>::operator[] ( const int index ) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= this->_size)
		throw std::exception();
	return this->_data[index];
}

template < typename T >
unsigned int	Array<T>::size ( void ) const
{
	return this->_size;
}
