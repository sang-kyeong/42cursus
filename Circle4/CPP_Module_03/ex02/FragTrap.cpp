#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap ( void ) :
	ClapTrap("no name", 100, 100, 30)
{
	std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::FragTrap ( std::string name ) :
	ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::FragTrap ( const FragTrap & other ) :
	ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::~FragTrap ( void )
{
	std::cout << "FragTrap " << this->_name << " destructed" << std::endl;
}

FragTrap &	FragTrap::operator= ( const FragTrap & other )
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys ( void )
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " try to high five to you" << std::endl;
	}
}


