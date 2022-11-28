#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void) {
	int		n;
	std::string	_name;
	Zombie	*zombie_horde;

	std::cout << "put number of zombie : ";
	std::cin >> n;
	if (std::cin.eof() || std::cin.fail() | n <= 0)
	{
		std::cout << "wrong input" << std::endl;
		return (0);
	}
	std::cin.ignore();
	std::cout << "put their name : ";
	std::cin >> _name;
	if (std::cin.eof())
	{
		std::cout << "wrong input" << std::endl;
		return (0);
	}
	zombie_horde = zombieHorde(n, _name);
	delete[] (zombie_horde);
	return (0);
}
