#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( int argc, char *argv[] )
{
	std::string	name;

	if (argc != 2)
		return (1);
	ScavTrap	player(argv[1]);
	ClapTrap	enemy("sangkkim");

	player.showStatus();
	enemy.showStatus();
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 12; i++)
	{
		enemy.attack(player.getName());
		player.takeDamage(enemy.getAttackDamage());
	}
	std::cout << std::endl << std::endl;

	player.showStatus();
	enemy.showStatus();
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 12; i++)
	{
		player.attack(enemy.getName());
		enemy.takeDamage(player.getAttackDamage());
	}

	std::cout << std::endl << std::endl;
	player.showStatus();
	enemy.showStatus();
	return (0);
}
