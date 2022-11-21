#include <iostream>
#include "ClapTrap.hpp"
#include "Battle.hpp"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "please input your name" << std::endl;
		return (1);
	}

	{
		ClapTrap	player(argv[1]), enemy("sangkkim");
		Battle		battle(player, enemy);

		std::string	buffer;
		std::cout << "Press Enter" << std::endl;
		std::getline(std::cin, buffer);

		battle.start();
		while (true)
		{
			battle.playerTurn();
			if (battle.isEnd())
				break ;
			battle.enemyTurn();
			if (battle.isEnd())
				break ;
		}
		battle.end();
	}
}
