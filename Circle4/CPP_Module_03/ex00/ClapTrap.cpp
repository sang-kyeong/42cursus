# include <iostream>
# include <string>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void ) :
	_name("no name"), _hit_points(ClapTrap::_max_hp),
	_energe_points(ClapTrap::_max_ep), _attack_damage(ClapTrap::_default_dmg)
{
	std::cout << "ClapTrap " << this->_name << " constructed" <<std::endl;
}

ClapTrap::ClapTrap ( std::string name ) :
	_name(name), _hit_points(ClapTrap::_max_hp),
	_energe_points(ClapTrap::_max_ep), _attack_damage(ClapTrap::_default_dmg)
{
	std::cout << "ClapTrap " << this->_name << " constructed" <<std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap & other ) :
	_name(other._name), _hit_points(other._hit_points),
	_energe_points(other._energe_points), _attack_damage(other._attack_damage)
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
	this->_energe_points = other._energe_points;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

void	ClapTrap::attack ( const std::string & target )
{
	if (this->_energe_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		this->_energe_points --;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", cousing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage ( unsigned int amount )
{
	if (this->_hit_points < amount)
	{
		int	actual_damage = this->_hit_points;
		this->_hit_points = ClapTrap::_max_hp;
		std::cout << "ClapTrap " << this->_name << " loose " << actual_damage << " points of hp" << std::endl;
	}
	else
	{
		this->_hit_points += ClapTrap::_max_hp;
		std::cout << "ClapTrap " << this->_name << " loose " << amount << " points of hp" << std::endl;
	}
}

void	ClapTrap::beRepaired ( unsigned int amount )
{
	if (this->_energe_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else if (ClapTrap::_max_hp - this->_hit_points < amount)
	{
		int	actual_repair = ClapTrap::_max_hp - this->_hit_points;
		this->_hit_points = ClapTrap::_max_hp;
		this->_energe_points --;
		std::cout << "ClapTrap " << this->_name << " repaied " << actual_repair << " points of hp" << std::endl;
	}
	else
	{
		this->_hit_points += ClapTrap::_max_hp;
		this->_energe_points --;
		std::cout << "ClapTrap " << this->_name << " repaied " << amount << " points of hp" << std::endl;
	}
}

const std::string &	ClapTrap::getName ( void )
{
	return (this->_name);
}

unsigned int	ClapTrap::getAttackDamage ( void )
{
	return (this->_attack_damage);
}

