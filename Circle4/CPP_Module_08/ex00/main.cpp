#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"
#include "Color.hpp"

int	main ( void )
{
	const int	array[] = {4, 12, 10, 222, 176, 0, 106, 42, 7};

	std::cout << std::endl << MAGENTA << "** Vector Test **" << NORMAL << std::endl;
	{
		std::vector<int> int_vector;
		for (int i=0; i<9; i++)
			int_vector.push_back(array[i]);

		std::vector<int>::iterator iter = easyfind(int_vector, 42);
		if (iter == int_vector.end())
			std::cout << RED << "didn't found" << NORMAL << std::endl;
		else
			std::cout << GREEN << "found" << NORMAL << std::endl;
	}

	std::cout << std::endl << MAGENTA << "** List Test **" << NORMAL << std::endl;
	{
		std::list<int> int_list;
		for (int i=0; i<9; i++)
			int_list.push_back(array[i]);

		std::list<int>::iterator iter = easyfind(int_list, 42);
		if (iter == int_list.end())
			std::cout << RED << "didn't found" << NORMAL << std::endl;
		else
			std::cout << GREEN << "found" << NORMAL << std::endl;
	}

	std::cout << std::endl << MAGENTA << "** Deque Test **" << NORMAL << std::endl;
	{
		std::deque<int> int_deque;
		for (int i=0; i<9; i++)
			int_deque.push_back(array[i]);

		std::deque<int>::iterator iter = easyfind(int_deque, 42);
		if (iter == int_deque.end())
			std::cout << RED << "didn't found" << NORMAL << std::endl;
		else
			std::cout << GREEN << "found" << NORMAL << std::endl;
	}
}
