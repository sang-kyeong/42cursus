#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"
#include "Color.hpp"

int	main ( void )
{
	int randoms[] = { \
		20,     79,    112,    251,    193,    176,    195,    155,     31,    160, \
		5,     18,     70,    203,      0,    227,    262,     17,    258,    287, \
		180,    123,    203,     74,     28,    231,    166,     69,    179,     68, \
		255,    180,    219,    239,    194,    181,    284,    294,    148,     39, \
		164,     40,    296,    177,    191,     57,    128,    175,    271,      4, \
		136,     52,     16,     16,    187,     73,    112,     63,    167,    293, \
		133,    248,    189,    247,     87,     69,     45,     83,     65,    276, \
		245,    178,     21,     76,    132,    108,     73,    181,     22,    130, \
		249,    295,      3,     10,     35,     99,     67,     52,     97,     47, \
		227,      2,    154,    295,    101,    232,     88,    298,     70,    201, \
	};
	srand(time(NULL));

	std::cout << std::endl << MAGENTA << "** Vector Test **" << NORMAL << std::endl;
	{
		std::vector<int> int_vector;
		for (int i=0; i<100; i++)
			int_vector.push_back(randoms[i]);
		try
		{
			int	target = rand() % 300;
			std::cout << "target : " << target << std::endl;
			std::vector<int>::iterator iter = easyfind(int_vector, target);
			std::cout << GREEN << "found " << *iter << NORMAL << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << RED << "didn't find" << NORMAL << std::endl;
		}
	}

	std::cout << std::endl << MAGENTA << "** List Test **" << NORMAL << std::endl;
	{
		std::list<int> int_list;
		for (int i=0; i<100; i++)
			int_list.push_back(randoms[i]);
		try
		{
			int	target = rand() % 300;
			std::cout << "target : " << target << std::endl;
			std::list<int>::iterator iter = easyfind(int_list, target);
			std::cout << GREEN << "found " << *iter << NORMAL << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << RED << "didn't find" << NORMAL << std::endl;
		}
	}

	std::cout << std::endl << MAGENTA << "** Deque Test **" << NORMAL << std::endl;
	{
		std::deque<int> int_deque;
		for (int i=0; i<100; i++)
			int_deque.push_back(randoms[i]);
		try
		{
			int	target = rand() % 300;
			std::cout << "target : " << target << std::endl;
			std::deque<int>::iterator iter = easyfind(int_deque, target);
			std::cout << GREEN << "found " << *iter << NORMAL << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << RED << "didn't find" << NORMAL << std::endl;
		}
	}
}
