#include <iostream>
#include <iomanip>

int main ( void )
{
	srand(time(NULL));

	int n;
	std::cout << "\t\t\tint randoms[] = { \\" << std::endl;
	for (int i = 0; i < 200; i++)
	{
		std::cout << "\t\t\t\t";
		for (int j = 0; j < 50; j++)
		{
			n = rand() / 1000000;
			std::cout << std::setw(6) << n << ", ";
		}
		std::cout << "\\" << std::endl;
	}
	std::cout << "\t\t\t};";
}
