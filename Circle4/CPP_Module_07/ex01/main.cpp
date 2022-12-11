#include <iostream>
#include "iter.hpp"
#include "Color.hpp"

void	ft_print_upper ( const char & c)
{
	std::cout << static_cast<char>(std::toupper(c));
}

void	ft_print_square ( const int & i)
{
	std::cout << (i * i) << ' ';
}

int	main ( void )
{
	int int_array[] = {1, 2, 3, 4, 5};
	double double_array[] = {42., 2.12, 36.5};
	char char_array[] = "sangkkim";

	std::cout << std::endl << MAGENTA << "** int - print **" << NORMAL << std::endl;
	iter(int_array, static_cast<size_t>(5), ft_print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** int - print square **" << NORMAL << std::endl;
	iter(int_array, static_cast<size_t>(5), ft_print_square);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** double - print **" << NORMAL << std::endl;
	iter(double_array, static_cast<size_t>(3), ft_print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** char - print **" << NORMAL << std::endl;
	iter(char_array, static_cast<size_t>(8), ft_print);
	std::cout << std::endl;

	std::cout << std::endl << MAGENTA << "** char - print upper **" << NORMAL << std::endl;
	iter(char_array, static_cast<size_t>(8), ft_print_upper);
	std::cout << std::endl;
}
