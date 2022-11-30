#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap ( void ) :
	ClapTrap("no name", FragTrap::_max_hp, FragTrap::_max_ep, FragTrap::_default_dmg)
{
	std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::FragTrap ( std::string name ) :
	ClapTrap(name, FragTrap::_max_hp, FragTrap::_max_ep, FragTrap::_default_dmg)
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
	this->_energe_points = other._energe_points;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

void	FragTrap::attack ( const std::string & target )
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_energe_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	FragTrap::takeDamage ( unsigned int amount )
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " is already down" << std::endl;
	}
	else
	{
		unsigned int	actual_damage = amount > this->_hit_points ? this->_hit_points : amount;
		this->_hit_points -= actual_damage;
		std::cout << "FragTrap " << this->_name << " loose " << actual_damage << "points of hp" << std::endl;
	}
}

void	FragTrap::beRepaired ( unsigned int amount )
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_energe_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		unsigned int	actual_repair = amount > (FragTrap::_max_hp - this->_hit_points) ? (FragTrap::_max_hp - this->_hit_points) : amount;
		this->_hit_points += actual_repair;
		std::cout << "FragTrap " << this->_name << " repaired " << actual_repair << "points of hp" << std::endl;
	}
}

void	FragTrap::highFivesGuys ( void )
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_energe_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " try to highfive to you" << std::endl;
	}
}


