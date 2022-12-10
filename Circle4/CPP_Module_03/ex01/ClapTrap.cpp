# include <iostream>
# include <string>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void ) :
	_name("no name"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructed" <<std::endl;
}

ClapTrap::ClapTrap ( std::string name ) :
	_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructed" <<std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap & other ) :
	_name(other._name), _hit_points(other._hit_points),
	_energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap " << this->_name << " constructed" <<std::endl;
}

ClapTrap::ClapTrap ( const std::string name, unsigned int hp, unsigned int ep, unsigned int dmg ) :
	_name(name), _hit_points(hp), _energy_points(ep), _attack_damage(dmg)
{
	std::cout << "ClapTrap " << this->_name << " constructed" <<std::endl;
}

ClapTrap::~ClapTrap ( void )
{
	std::cout << "ClapTrap " << this->_name << " destructed" <<std::endl;
}

ClapTrap &	ClapTrap::operator= ( const ClapTrap & other )
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

void	ClapTrap::attack ( const std::string & target )
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		this->_energy_points --;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage ( unsigned int amount )
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is down" << std::endl;
	}
	else if (this->_hit_points < amount)
	{
		int	actual_damage = this->_hit_points;
		this->_hit_points = 0;
		std::cout << this->_name << " loose " << actual_damage << " points of hp" << std::endl;
	}
	else
	{
		this->_hit_points -= amount;
		std::cout << this->_name << " loose " << amount << " points of hp" << std::endl;
	}
}

void	ClapTrap::beRepaired ( unsigned int amount )
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is down" << std::endl;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		this->_hit_points += amount;
		this->_energy_points--;
		std::cout << this->_name << " repaired " << amount << " points of hp" << std::endl;
	}
}

const std::string &	ClapTrap::getName (void) const
{
	return (this->_name);
}
unsigned int		ClapTrap::getHitPoints ( void ) const
{
	return (this->_hit_points);
}
unsigned int		ClapTrap::getEnergyPoints ( void ) const
{
	return (this->_energy_points);
}
unsigned int		ClapTrap::getAttackDamage ( void ) const
{
	return (this->_attack_damage);
}

void		ClapTrap::getName ( const std::string & name )
{
	this->_name = name;
}
void		ClapTrap::getHitPoints ( unsigned int points )
{
	this->_hit_points = points;
}
void		ClapTrap::getEnergyPoints ( unsigned int points )
{
	this->_energy_points = points;
}
void		ClapTrap::getAttackDamage ( unsigned int points )
{
	this->_attack_damage = points;
}

void		ClapTrap::showStatus ( void )
{
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "HP : " << this->_hit_points << std::endl;
	std::cout << "EP : " << this->_energy_points << std::endl;
}
