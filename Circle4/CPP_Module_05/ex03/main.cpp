#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Color.hpp"

int	main ( void )
{
	srand(time(NULL));
	Intern	intern;
	// Exception in sign
	std::cout << std::endl << MAGENTA << "** Intern make form Test **" << WHITE << std::endl;
	{
		std::cout << std::endl << MAGENTA << "** Shrubbery Creation **" << WHITE << std::endl;
		AForm	*form;
		form = intern.makeForm("shrubbery creation", "sangkkim");
		std::cout << *form << std::endl;
		delete form;
		std::cout << std::endl << MAGENTA << "** Robotomy Request **" << WHITE << std::endl;
		form = intern.makeForm("robotomy request", "minjekan");
		std::cout << *form << std::endl;
		delete form;
		std::cout << std::endl << MAGENTA << "** Presidential Pardon **" << WHITE << std::endl;
		form = intern.makeForm("presidential pardon", "seongwch");
		std::cout << *form << std::endl;
		delete form;
		std::cout << std::endl << MAGENTA << "** Fail **" << WHITE << std::endl;
		form = intern.makeForm("fail sangkkim", "sangkkim");
	}
	system("leaks ex03 | grep total");
	return 0;
}