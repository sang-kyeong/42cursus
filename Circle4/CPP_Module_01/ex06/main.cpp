#include <string>
#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		my_harl;

	if (argc != 2)
		return (126);

	my_harl.filter(argv[1]);
	return (0);
}
