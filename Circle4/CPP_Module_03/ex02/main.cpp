#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	std::string	name;

	std::cout << "Enter your name" << std::endl;
	std::cin >> name;
	if (std::cin.fail())
		return (1);
	ScavTrap	player(name);
	FragTrap	enemy("sangkkim");

	for (int i = 0; i < 12; i++)
	{
		player.attack(enemy.getName());
		enemy.takeDamage(player.getAttackDamage());
		enemy.highFivesGuys();
		enemy.beRepaired(enemy.getAttackDamage());
	}
	player.guardGate();
	player.guardGate();
	player.guardGate();
	enemy.beRepaired(enemy.getAttackDamage());
	return (0);
}
