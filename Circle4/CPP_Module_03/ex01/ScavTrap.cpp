#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) :
	ClapTrap("no name", ScavTrap::_max_hp, ScavTrap::_max_ep, ScavTrap::_default_dmg),
	_mode(normal_mode)
{
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap ( std::string name ) :
	ClapTrap(name, ScavTrap::_max_hp, ScavTrap::_max_ep, ScavTrap::_default_dmg),
	_mode(normal_mode)
{
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap & other ) :
	ClapTrap(other),
	_mode(normal_mode)
{
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap ( void )
{
	std::cout << "ScavTrap " << this->_name << " destructed" << std::endl;
}

ScavTrap &	ScavTrap::operator= ( const ScavTrap & other )
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energe_points = other._energe_points;
	this->_attack_damage = other._attack_damage;
	this->_mode = other._mode;
	return (*this);
}

void	ScavTrap::attack ( const std::string & target )
{
	if (this->_energe_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << "points of damage!" << std::endl;
	}
}

void	ScavTrap::takeDamage ( unsigned int amount )
{
	if (this->_mode == gate_keeper_mode)
	{
		std::cout << "ScavTrap " << this->_name << " cannot repaire self in Gate Keeper Mode" << std::endl;
	}
	else
	{
		unsigned int	actual_damage = amount > this->_hit_points ? this->_hit_points : amount;
		this->_hit_points -= actual_damage;
		std::cout << "ScavTrap " << this->_name << " loose " << actual_damage << "points of hp" << std::endl;
	}
}

void	ScavTrap::beRepaired ( unsigned int amount )
{
	if (this->_mode == gate_keeper_mode)
	{
		std::cout << "ScavTrap " << this->_name << " cannot repaire self in Gate Keeper Mode" << std::endl;
	}
	else if (this->_energe_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		unsigned int	actual_repair = amount > (ScavTrap::_max_hp - this->_hit_points) ? (ScavTrap::_max_hp - this->_hit_points) : amount;
		this->_hit_points += actual_repair;
		std::cout << "ScavTrap " << this->_name << " repaired " << actual_repair << "points of hp" << std::endl;
	}
}

void	ScavTrap::guardGate ( void )
{
	if (this->_mode == normal_mode)
	{
		this->_mode = gate_keeper_mode;
		std::cout << "ScavTrap " << this->_name << " is Gate Keeper Mode now" << std::endl;
	}
	else
	{
		this->_mode = normal_mode;
		std::cout << "ScavTrap " << this->_name << " is not Gate Keeper Mode now" << std::endl;
	}
}

const std::string &	ScavTrap::getName (void)
{
	return (this->_name);
}

unsigned int	ScavTrap::getAttackDamage ( void )
{
	return (this->_attack_damage);
}
