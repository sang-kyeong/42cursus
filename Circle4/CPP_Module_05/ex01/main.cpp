#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

int	main ( void )
{
	// Exception in Constructor
	std::cout << MAGENTA << "Exception in Constructor Test1" << NORMAL << std::endl;
	try
	{
		Form	form("form", 1, 151);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// Exception in Constructor
	std::cout << MAGENTA << "Exception in Constructor Test2" << NORMAL << std::endl;
	try
	{
		Form	form("form", 0, 151);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// Exception in sign
	std::cout << std::endl << MAGENTA << "Exception in sign Test" << NORMAL << std::endl;
	{
		Bureaucrat		Tom("Tom", 10);
		Bureaucrat		Kevin("Kevin", 30);
		std::cout << Tom << std::endl << Kevin << std::endl;

		Form			form1("Top Secret", 1, 1);
		Form			form2("Very Important", 20, 1);
		Form			form3("42's dark Secret", 42, 42);
		std::cout << form1 << std::endl << form2 << std::endl << form3 << std::endl;

		Kevin.signForm(form3);
		Kevin.signForm(form2);
		Tom.signForm(form2);
		Tom.signForm(form1);
		std::cout << form1 << std::endl << form2 << std::endl << form3 << std::endl;
	}
	return 0;
}