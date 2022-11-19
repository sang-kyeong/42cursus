#include <iostream>
#include "ClapTrap.hpp"

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "please input two players' name." << std::endl;
		return 1;
	}

	ClapTrap player1(argv[1]);
	ClapTrap player2(argv[2]);

	player1.printInfo();
	player2.printInfo();

	for (int i = 0; i < 12; i++)
	{
		player1.attack(player2.getName());
		player2.takeDamage(player1.getAttackDamage());
	}

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		player2.beRepaired(3);
	}

	player1.printInfo();
	player2.printInfo();
}