#include <iostream>
#include <algorithm>
#include <exception>
#include "Span.hpp"
#include "Color.hpp"

Span::Span ( void ) : _N(0), _vector()
{
	std::cout << BLACK << "[Span] default constructor" << NORMAL << std::endl;
}
Span::Span ( unsigned int N ) : _N(N), _vector()
{
	std::cout << BLACK << "[Span] N constructor" << NORMAL << std::endl;
}
Span::Span ( const Span & other ) : _N(other._N), _vector(other._vector)
{
	std::cout << BLACK << "[Span] copy constructor" << NORMAL << std::endl;
}
Span::~Span ( void )
{
	std::cout << BLACK << "[Span] destructor" << NORMAL << std::endl;
}
	
Span &	Span::operator= (const Span & other )
{
	if (this == &other)
		return *this;

	this->_N = other._N;
	this->_vector = other._vector;
	return  *this;
}

void	Span::addNumber ( int number )
{
	if (this->_vector.size() == this->_N)
		throw std::exception();
	this->_vector.push_back(number);
}

void	Span::addNumbers ( std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t	left = static_cast<size_t>(this->_N) - this->_vector.size();
	if (left < static_cast<size_t>(end - begin))
		throw std::exception();
	this->_vector.insert(this->_vector.begin(), begin, end);
}

unsigned int	Span::shortestSpan ( void )
{
	if (this->_vector.size() <= 1)
		throw std::exception();

	std::sort(this->_vector.begin(), this->_vector.end());

	unsigned int	shortest = this->_vector.at(1) - this->_vector.at(0);
	for (std::vector<int>::iterator iter = this->_vector.begin() + 1;
		iter != this->_vector.end(); iter++)
	{
		unsigned int span = *(iter - 1) - *iter;
		if (shortest > span)
			shortest = span;
	}
	return shortest;
}

unsigned int	Span::longestSpan ( void )
{
	if (this->_vector.size() <= 1)
		throw std::exception();

	std::sort(this->_vector.begin(), this->_vector.end());

	unsigned int	longest = this->_vector.at(this->_vector.size() - 1) - this->_vector.at(0);
	return longest;
}
