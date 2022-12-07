#include <iostream>
#include "Intern.hpp"


Intern::Intern ( void )
{
	std::cout << GREEN << "[Intern] default constructor" << NORMAL << std::endl;
}

Intern::Intern ( const Intern & other )
{
	std::cout << GREEN << "[Intern] copy constructor" << NORMAL << std::endl;
}

Intern::~Intern ( void )
{
	std::cout << RED << "[Intern] destructor" << NORMAL << std::endl;
}

Intern &	Intern::operator= ( const Intern & other )
{
	return *this;
}

AForm *	Intern::makeForm ( const std::string form_name, const std::string target )
{
	AForm	*form;
	int	number \
		= ((form_name == "shrubbery creation") * 1) \
		+ ((form_name == "robotomy request") * 2) \
		+ ((form_name == "presidential pardon") * 3);
	
	switch (number)
	{
	case 1:
		form = new ShrubberyCreationForm(target);
		break ;
	case 2:
		form = new RobotomyRequestForm(target);
		break ;
	case 3:
		form = new PresidentialPardonForm(target);
		break ;
	default :
		std::cout << RED << "Intern didn't creates " << form_name << " form" << WHITE << std::endl;
		return NULL;
		break ;
	}
	std::cout << GREEN << "Intern creates " << form_name << " form" << WHITE << std::endl;
	return from;
}
