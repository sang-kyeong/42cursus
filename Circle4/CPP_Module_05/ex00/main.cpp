#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

int	main ( void )
{
	// Exception in Constructor
	std::cout << MAGENTA << "** Exception in Constructor Test1 **" << WHITE << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 0);
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	// Exception in Constructor
	std::cout << MAGENTA << "** Exception in Constructor Test2 **" << WHITE << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 151);
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	// Exception in Decrement
	std::cout << std::endl << MAGENTA << "** Exception in Decrement Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 150);
		std::cout << wrong << std::endl;
		wrong.decreaseGrade();
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	// No exception
	std::cout << std::endl << MAGENTA << "** No Exception Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 150);
		std::cout << wrong << std::endl;
		wrong.increaseGrade();
		std::cout << wrong << std::endl;
		wrong.increaseGrade();
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}
	system("leaks ex00 | grep total");
	return 0;
}