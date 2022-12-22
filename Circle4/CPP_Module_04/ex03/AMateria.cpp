#include <iostream>
#include "AMateria.hpp"
#include "Color.hpp"

AMateria::AMateria ( void ) : _type()
{
	std::cout << BLACK << "[AMateria] default constructor" << NORMAL << std::endl;
}

AMateria::AMateria ( const AMateria & other ) : _type(other._type)
{
	std::cout << BLACK << "[AMateria] copy constructor" << NORMAL << std::endl;
}

AMateria::AMateria ( std::string const & type ) : _type(type)
{
	std::cout << BLACK << "[AMateria] type constructor" << NORMAL << std::endl;
}

AMateria::~AMateria ( void )
{
	std::cout << BLACK << "[AMateria] destructor" << NORMAL << std::endl;
}

AMateria &	AMateria::operator= ( const AMateria & other )
{
	if (this == &other)
		return *this;

	this->_type = other._type;
	return *this;
}

std::string const &	AMateria::getType ( void ) const
{
	return this->_type;
}

void	AMateria::use ( ICharacter & target )
{
	std::cout << BLACK << "* uses a materia at " << target.getName() << " but it doesn't work *" << NORMAL << std::endl;
}
