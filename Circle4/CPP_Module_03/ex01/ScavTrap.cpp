#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) : ClapTrap(), gate_keeper_mode(false) {
	std::cout << "A ClapTrap is created." << std::endl;
}
ScavTrap::ScavTrap ( const ScavTrap & other ) : ClapTrap(other), gate_keeper_mode(other.gate_keeper_mode) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}
ScavTrap::ScavTrap ( std::string name ) : ClapTrap(name, 100, 50, 20), gate_keeper_mode(false) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}
ScavTrap::ScavTrap ( std::string name, int hp, int ep, int damage) : ClapTrap(name, hp, ep, damage), gate_keeper_mode(false) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}

ScavTrap &	ScavTrap::operator= ( const ScavTrap & other ) {
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	this->alive = other.alive;
	this->gate_keeper_mode = other.gate_keeper_mode;
	return (*this);
}

ScavTrap::~ScavTrap ( void ) {
	std::cout << "ScavTrap " << this->getName() <<  " is broken" << std::endl;
}

void	ScavTrap::attack ( const std::string& target ) {
	if (this->gate_keeper_mode)
		std::cout << "ScavTrap " << this->getName() << " is [Gate Keeper Mode]." << std::endl;
	else if (this->alive == false)
		std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " doesn't have enough energy." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
}
void	ScavTrap::takeDamage ( unsigned int amount ) {
	if (asdf)
}

void	ScavTrap::beRepaired ( unsigned int amount ) {
	if (this->gate_keeper_mode)
		std::cout << "ScavTrap " << this->getName() << " is [Gate Keeper Mode]." << std::endl;
	else if (this->alive == false)
		std::cout << "ScavTrap " << this->name << " is already destroyed." << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ScavTrap " << this->name << " doesn't have enough energy." << std::endl;
	else
	{
		int		repaired = -this->hit_points;

		this->hit_points += amount;
		if (this->hit_points > ClapTrap::max_hit_points)
			this->hit_points = ClapTrap::max_hit_points;
		this->energy_points--;
		repaired += this->hit_points;
		std::cout << "ScavTrap " << this->name << " repaired itself, it got " << repaired << " hit points back!" << std::endl;
		if (this->hit_points == ClapTrap::max_hit_points)
			std::cout << "ScavTrap " << this->name << " is get max hit points now!" << std::endl;
	}
}

void	ScavTrap::GuardGate ( void )
{
	
}