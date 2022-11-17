#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void )
{
	this->name = "no name";
	this->hit_points = 0;
	this->energy_points = 0;
	this->attack_damage = 0;
	std::cout << "A ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap & other )
{
	*this = other;
	std::cout << "A ClapTrap " << this->name << " is created" << std::endl;
}

ClapTrap::ClapTrap ( std::string name )
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "A ClapTrap " << this->name << " is created" << std::endl;
}

ClapTrap &	ClapTrap::operator= (const ClapTrap &other )
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap ( void )
{
	std::cout << this->name <<  " is broken" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void	ClapTrap::takeDamage ( unsigned int amount )
{
	std::cout << "ClapTrap " << this->name << " is attacked, it lose " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
}

void	ClapTrap::beRepaired ( unsigned int amount )
{
	std::cout << "ClapTrap " << this->name << " repaired itself, it got " << amount << " hit points back!" << std::endl;
	this->hit_points += amount;
	this->energy_points--;
}
