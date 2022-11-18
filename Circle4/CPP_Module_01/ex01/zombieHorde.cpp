#include <sstream>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie	*zombie_horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::stringstream		ss;
		ss << name << " No." << i;
		zombie_horde[i].set_name(ss.str());
	}
	return (zombie_horde);
}
