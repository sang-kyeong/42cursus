#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) :
	ClapTrap("no name", 100, 50, 20), _mode(normal_mode)
{
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap ( std::string name ) :
	ClapTrap(name, 100, 50, 20), _mode(normal_mode)
{
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap & other ) :
	ClapTrap(other), _mode(normal_mode)
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
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_mode = other._mode;
	return (*this);
}

void	ScavTrap::attack ( const std::string & target )
{
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate ( void )
{
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is down" << std::endl;
	}
	else if (this->_mode == normal_mode)
	{
		this->_mode = gate_keeper_mode;
		std::cout << "ScavTrap " << this->_name << " is [Gate keeper] mode now" << std::endl;
	}
	else
	{
		this->_mode = normal_mode;
		std::cout << "ScavTrap " << this->_name << " is [Normal] mode now" << std::endl;
	}
}
