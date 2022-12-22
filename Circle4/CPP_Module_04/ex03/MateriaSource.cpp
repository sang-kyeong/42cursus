#include <iostream>
#include "MateriaSource.hpp"
#include "Color.hpp"

MateriaSource::MateriaSource ( void )
{
	std::cout << BLACK << "[MateriaSource] default constructor" << NORMAL << std::endl;
}

MateriaSource::MateriaSource ( const MateriaSource & other )
{
	for (int i = 0; i < 4; i++)
	{
		if (other._memory[i] != NULL)
			this->_memory[i] = other._memory[i]->clone();
		else
			this->_memory[i] = NULL;
	}
	std::cout << BLACK << "[MateriaSource] copy constructor" << NORMAL << std::endl;
}

MateriaSource::~MateriaSource ( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i] != NULL)
			delete this->_memory[i];
	}
	std::cout << BLACK << "[MateriaSource] destructor" << NORMAL << std::endl;
}

MateriaSource &	MateriaSource::operator= ( const MateriaSource & other )
{
	if (this == &other)
		return *this;

	this->~MateriaSource();
	for (int i = 0; i < 4; i++)
	{
		if (other._memory[i] != NULL)
			this->_memory[i] = other._memory[i]->clone();
		else
			this->_memory[i] = NULL;
	}
	return *this;
}

void		MateriaSource::learnMateria ( AMateria * materia )
{
	if (materia == NULL)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i] == NULL)
		{
			this->_memory[i] = materia;
			break ;
		}
	}
}

AMateria *	MateriaSource::createMateria ( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i] != NULL && this->_memory[i]->getType() == type)
		{
			return this->_memory[i]->clone();
		}
	}
	return NULL;
}
