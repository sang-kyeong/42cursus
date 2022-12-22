#include <iostream>
#include "Ice.hpp"
#include "Color.hpp"

Ice::Ice ( void ) : AMateria("ice")
{
	std::cout << BLACK << "[Ice] default constructor" << NORMAL << std::endl;
}

Ice::Ice ( const Ice & other ) : AMateria(other)
{
	std::cout << BLACK << "[Ice] copy constructor" << NORMAL << std::endl;
}

Ice::~Ice ( void )
{
	std::cout << BLACK << "[Ice] destructor" << NORMAL << std::endl;
}


Ice &	Ice::operator= ( const Ice & other )
{
	if (this == &other)
		return *this;

	AMateria::operator=(other);
	return *this;
}

AMateria*	Ice::clone ( void ) const
{
	return new Ice(*this);
}

void		Ice::use ( ICharacter & target )
{
	std::cout << "* shoots an " << BLUE << "ice bolt" << NORMAL << " at " << target.getName() << " *" << std::endl;
}
