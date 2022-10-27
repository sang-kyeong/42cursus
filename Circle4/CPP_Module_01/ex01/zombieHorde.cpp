#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*zombie_horde = new Zombie[N];
	std::string	_name;

	for (int i = 0; i < N; i++)
	{
		_name = name;
		_name.append(" No.");
		_name.append(std::to_string(i + 1));
		zombie_horde[i].set_name(_name);
	}
	return (zombie_horde);
}
