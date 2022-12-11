#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void	test_leaks(void)
{
	system("leaks ex02 | grep total");
}

int main(int, char**)
{
	atexit(test_leaks);
	Array<int> numbers(MAX_VAL);												// constructor
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;														// [] operator
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;												// copy constructor
		Array<int> test(tmp);													// copy constructor 2
	}																			// destructor x 2

	for (int i = 0; i < MAX_VAL; i++)											// check data
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try																			// try too low index
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try																			// try too high index
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)											// [] operator
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;																	// destructor
}
