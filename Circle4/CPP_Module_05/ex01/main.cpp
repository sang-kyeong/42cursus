#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

int	main ( void )
{
	
	std::cout << std::endl << MAGENTA << "** Too Low Exception in Constructor Test **" << WHITE << std::endl;
	try
	{
		Form	form("form", 1, 151);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << MAGENTA << "** Too High Exception in Constructor Test **" << WHITE << std::endl;
	try
	{
		Form	form("form", 0, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// Exception in sign
	std::cout << std::endl << MAGENTA << "** Too Low Exception in sign Test **" << WHITE << std::endl;
	{
		Bureaucrat		Maggot("Maggot", 42);
		Form			form1("42 Secret", 42, 1);
		Form			form2("Top Secret", 40, 1);

		
		std::cout << Maggot << std::endl << form1 << std::endl << form2 << std::endl;
		Maggot.signForm(form1);
		Maggot.signForm(form2);

		std::cout << std::endl << MAGENTA << "** Already Signed Exception in sign Test **" << WHITE << std::endl;
		std::cout << "increase" << std::endl;
		Maggot.increaseGrade();
		std::cout << "increase" << std::endl;
		Maggot.increaseGrade();
		std::cout << Maggot << std::endl << form1 << std::endl << form2 << std::endl;
		Maggot.signForm(form1);
		Maggot.signForm(form2);
	}
	return 0;
}