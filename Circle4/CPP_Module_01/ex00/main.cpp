#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie		*zombie;

	zombie = newZombie("A");
	zombie->announce();
	randomChump("B");
	delete(zombie);
	return (0);
}