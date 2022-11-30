#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	std::string	name;

	std::cout << "Enter your name" << std::endl;
	std::cin >> name;
	if (std::cin.fail())
		return (1);
	ClapTrap	player(name), enemy("sangkkim");

	for (int i = 0; i < 12; i++)
	{
		player.attack(enemy.getName());
		enemy.takeDamage(player.getAttackDamage());
		enemy.beRepaired(enemy.getAttackDamage());
	}
	return (0);
}
