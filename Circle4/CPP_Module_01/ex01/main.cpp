#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	int			N;
	std::string	name;
	Zombie		*horde;

	std::cin >> N;
	std::cin >> name;
	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete (horde);
	return (0);
}
