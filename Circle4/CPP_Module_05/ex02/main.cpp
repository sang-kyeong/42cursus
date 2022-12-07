#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Color.hpp"

int	main ( void )
{
	srand(time(NULL));
	Bureaucrat		President("President", 1);
	Bureaucrat		Maggot("Maggot", 70);

	ShrubberyCreationForm	form1("sangkkim");		// 145, 137
	RobotomyRequestForm		form2("minjekan");		//  72,  45
	PresidentialPardonForm	form3("seongwch");		//  25,   5

	std::cout << std::endl << MAGENTA << "** Maggot sign Test **" << WHITE << std::endl;
	{
		std::cout << MAGENTA << "** Shrubbery Creation **" << WHITE << std::endl;
		std::cout << Maggot << std::endl << form1 << std::endl;
		Maggot.signForm(form1);
		std::cout << MAGENTA << "** Robotomy Request **" << WHITE << std::endl;
		std::cout << Maggot << std::endl << form2 << std::endl;
		Maggot.signForm(form2);
		std::cout << MAGENTA << "** Presidential Pardon **" << WHITE << std::endl;
		std::cout << Maggot << std::endl << form3 << std::endl;
		Maggot.signForm(form3);
	}

	std::cout << std::endl << MAGENTA << "** President execution Test **" << WHITE << std::endl;
	{
		std::cout << MAGENTA << "** Shrubbery Creation **" << WHITE << std::endl;
		std::cout << President << std::endl << form1 << std::endl;
		President.executeForm(form1);
		std::cout << MAGENTA << "** Robotomy Request **" << WHITE << std::endl;
		std::cout << President << std::endl << form2 << std::endl;
		President.executeForm(form2);
		std::cout << MAGENTA << "** Presidential Pardon **" << WHITE << std::endl;
		std::cout << President << std::endl << form3 << std::endl;
		President.executeForm(form3);
	}

	std::cout << std::endl << MAGENTA << "** President sign Test **" << WHITE << std::endl;
	{
		std::cout << MAGENTA << "** Shrubbery Creation **" << WHITE << std::endl;
		std::cout << President << std::endl << form1 << std::endl;
		President.signForm(form1);
		std::cout << MAGENTA << "** Robotomy Request **" << WHITE << std::endl;
		std::cout << President << std::endl << form2 << std::endl;
		President.signForm(form2);
		std::cout << MAGENTA << "** Presidential Pardon **" << WHITE << std::endl;
		std::cout << President << std::endl << form3 << std::endl;
		President.signForm(form3);
		President.executeForm(form3);
	}
	system("leaks ex02 | grep total");
	return 0;
}