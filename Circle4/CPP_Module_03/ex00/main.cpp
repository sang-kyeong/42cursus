#include <iostream>
#include "ClapTrap.hpp"
#include "Battle.hpp"

void	check_leaks ( void ) {
	system("leaks ex00");
}

int main (int argc, char *argv[])
{
	atexit(check_leaks);
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
