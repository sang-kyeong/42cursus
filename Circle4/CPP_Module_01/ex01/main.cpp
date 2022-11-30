#include <string>
#include <iostream>
#include <sstream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main ( int argc, char *argv[] )
{
	unsigned int		n;
	std::stringstream	ss;
	Zombie				*zombie_horde;

	if (argc != 3)
		return (1);
	ss << argv[1];
	ss >> n;
	if (ss.fail())
		return (1);
	std::cout << "Name of Zombies : " << argv[2] << std::endl;
	std::cout << "Number of Zombies : " << n << std::endl << std::endl;

	zombie_horde = zombieHorde(n, argv[2]);
	for (int i = 0; i < n; i++)
		zombie_horde[i].announce();
	delete[] (zombie_horde);
	return (0);
}
