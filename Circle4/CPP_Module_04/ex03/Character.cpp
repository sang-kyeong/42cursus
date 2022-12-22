#include <iostream>
#include "Character.hpp"
#include "Color.hpp"

Character::Character ( void ) : _name()
{
	std::cout << BLACK << "[Character] default constructor" << NORMAL << std::endl;
}

Character::Character ( const Character & other ) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << BLACK << "[Character] default constructor" << NORMAL << std::endl;
}

Character::Character ( std::string name ) : _name(name)
{
	std::cout << BLACK << "[Character] default constructor" << NORMAL << std::endl;
}

Character::~Character ( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << BLACK << "[Character] default constructor" << NORMAL << std::endl;
}

Character &	Character::operator= ( const Character & other )
{
	if (this == &other)
		return *this;

	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];

		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

std::string const &	Character::getName ( void ) const
{
	return this->_name;
}

void	Character::equip ( AMateria *m )
{
	if (m == NULL)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip ( int idx )
{
	this->_inventory[idx] = NULL;
}

void	Character::use ( int idx, ICharacter & target )
{
	if (this->_inventory[idx] == NULL)
		return ;

	this->_inventory[idx]->use(target);
}
