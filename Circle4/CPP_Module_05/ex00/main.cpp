#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

int	main ( void )
{
	std::cout << std::endl << MAGENTA << "** Grade Too High Exception in Constructor Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat bureaucrat("sangkkim", 0);
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	std::cout << std::endl << MAGENTA << "** Grade Too Low Exception in Constructor Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat bureaucrat("sangkkim", 151);
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	std::cout << std::endl << MAGENTA << "** Grade Too Low Exception in Decrement Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat bureaucrat("sangkkim", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decreaseGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	std::cout << std::endl << MAGENTA << "** Grade Too High Exception in Increment Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat bureaucrat("sangkkim", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.increaseGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}

	// No exception
	std::cout << std::endl << MAGENTA << "** No Exception Test **" << WHITE << std::endl;
	try
	{
		Bureaucrat bureaucrat("sangkkim", 150);
		std::cout << bureaucrat << std::endl;
		std::cout << "increase" << std::endl;
		bureaucrat.increaseGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << "increase" << std::endl;
		bureaucrat.increaseGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << "decrease" << std::endl;
		bureaucrat.decreaseGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << WHITE << std::endl;
	}
	system("leaks ex00 | grep total");
	return 0;
}