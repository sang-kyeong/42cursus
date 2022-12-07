#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main ( void )
{
	// Exception in Constructor
	std::cout << MAGENTA << "Exception in Constructor Test1" << NORMAL << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 0);
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// Exception in Constructor
	std::cout << MAGENTA << "Exception in Constructor Test2" << NORMAL << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 151);
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// Exception in Decrement
	std::cout << std::endl << MAGENTA << "Exception in Decrement Test" << NORMAL << std::endl;
	try
	{
		Bureaucrat wrong("sangkkim", 150);
		std::cout << wrong << std::endl;
		wrong.decreaseGrade();
		std::cout << wrong << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// No exception
	std::cout << std::endl << MAGENTA << "No Exception Test" << NORMAL << std::endl;
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
		std::cout << e.what() << std::endl;
	}
	return 0;
}