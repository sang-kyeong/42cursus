#include <iostream>
#include "Brain.hpp"
#include "Color.hpp"

Brain::Brain ( void )
{
	std::cout << GREEN << "[Brain] default constructor" << WHITE << std::endl;
}

Brain::Brain ( const Brain & other )
{
	*this = other;
	std::cout << GREEN << "[Brain] copy constructor" << WHITE << std::endl;
}
	
Brain::~Brain ( void )
{
	std::cout << RED << "[Brain] destructor" << WHITE << std::endl;
}

Brain &	Brain::operator= ( const Brain & other )
{
	for (int i = 0; i < 100 ; i++)
		this->_ideas[i] = other._ideas[i];
	return *this;
}
