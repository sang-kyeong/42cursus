#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void) {
	Zombie	*zombie;

	zombie = newZombie("heap");
	zombie->anounce();
	randomChump("stack");
	zombie->anounce();
	delete (zombie);
}
