#include <iostream>
#include "ICharacter.hpp"
#include "Color.hpp"

ICharacter::ICharacter ( void )
{
	std::cout << BLACK << "[ICharacter] default constructor" << NORMAL << std::endl;
}

ICharacter::ICharacter ( const ICharacter & other )
{
	(void)other;
	std::cout << BLACK << "[ICharacter] copy constructor" << NORMAL << std::endl;
}

ICharacter::~ICharacter ( void )
{
	std::cout << BLACK << "[ICharacter] destructor" << NORMAL << std::endl;
}

ICharacter &	ICharacter::operator= ( const ICharacter & other )
{
	(void)other;
	return *this;
}
