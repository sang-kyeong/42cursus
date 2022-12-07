#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main ( void )
{
	// Exception in sign
	std::cout << std::endl << MAGENTA << "Exception in sign Test" << NORMAL << std::endl;
	{
		Bureaucrat		President("President", 1);
		Bureaucrat		Tom("Tom", 72);
		Bureaucrat		Kevin("Kevin", 138);
		std::cout << Tom << std::endl << Kevin << std::endl;

		ShrubberyCreationForm	form1("ShrubberyCreationForm");		// 145, 137
		RobotomyRequestForm	form2("RobotomyRequestForm");			//  72,  45
		PresidentialPardonForm	form3("PresidentialPardonForm");	//  25,   5
		std::cout << form1 << std::endl << form2 << std::endl << form3 << std::endl;

		Kevin.signForm(form1);
		Kevin.executeForm(form1);
		Kevin.increaseGrade();
		Kevin.executeForm(form1);

		Tom.executeForm(form1);
		Tom.executeForm(form2);

		President.signForm(form2);
		President.executeForm(form2);
		President.signForm(form3);
		President.executeForm(form3);
	}
	return 0;
}