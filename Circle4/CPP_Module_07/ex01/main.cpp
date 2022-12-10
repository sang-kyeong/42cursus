#include <iostream>
#include "iter.hpp"
#include "Color.hpp"

void	my_toupper (char & c)
{
	c = static_cast<char>(std::toupper(c));
}

void	my_square (int & i)
{
	i = i * i;
}

int	main ( void )
{
	int int_array[] = {1, 2, 3, 4, 5};
	double double_array[] = {42., 2.12, 36.5};
	char char_array[] = "sangkkim";

	std::cout << std::endl << MAGENTA << "** int - print **" << NORMAL << std::endl;
	iter(int_array, static_cast<size_t>(5), print<int>);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** int - square & print **" << NORMAL << std::endl;
	iter(int_array, static_cast<size_t>(5), my_square);
	iter(int_array, static_cast<size_t>(5), print<int>);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** double - print **" << NORMAL << std::endl;
	iter(double_array, static_cast<size_t>(3), print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** char - print **" << NORMAL << std::endl;
	iter(char_array, static_cast<size_t>(8), print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** char - toupper & print **" << NORMAL << std::endl;
	iter(char_array, static_cast<size_t>(8), my_toupper);
	iter(char_array, static_cast<size_t>(8), print);
	std::cout << std::endl;
}