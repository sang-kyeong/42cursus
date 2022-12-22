#include <iostream>
#include "Cure.hpp"
#include "Color.hpp"

Cure::Cure ( void ) : AMateria("cure")
{
	std::cout << BLACK << "[Cure] default constructor" << NORMAL << std::endl;
}

Cure::Cure ( const Cure & other ) : AMateria(other)
{
	std::cout << BLACK << "[Cure] copy constructor" << NORMAL << std::endl;
}

Cure::~Cure ( void )
{
	std::cout << BLACK << "[Cure] destructor" << NORMAL << std::endl;
}


Cure &	Cure::operator= ( const Cure & other )
{
	if (this == &other)
		return *this;

	AMateria::operator=(other);
	return *this;
}

AMateria*	Cure::clone ( void ) const
{
	return new Cure(*this);
}

void		Cure::use ( ICharacter & target )
{
	std::cout << "* " << BLUE << "heals" << NORMAL << " " << target.getName() << "'s wounds *" << std::endl;
}
