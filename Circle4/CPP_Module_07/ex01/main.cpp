#include <iostream>
#include "iter.hpp"
#include "Color.hpp"

void	megaphone (char & c)
{
	std::cout << static_cast<char>(std::toupper(c));
}

int	main ( void )
{
	int int_array[] = {1, 2, 3, 4, 5};
	double double_array[] = {42., 2.12, 35};
	char char_array[] = "sangkkim";

	std::cout << std::endl << MAGENTA << "** int - print **" << NORMAL << std::endl;
	iter(int_array, static_cast<size_t>(5), print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** double - print **" << NORMAL << std::endl;
	iter(double_array, static_cast<size_t>(3), print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** char - print **" << NORMAL << std::endl;
	iter(char_array, static_cast<size_t>(8), print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** char - toupper **" << NORMAL << std::endl;
	iter(char_array, static_cast<size_t>(8), megaphone);
	std::cout << std::endl;
}