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

}

AForm *	Intern::makeForm ( const std::string form_name, const std::string target )
{
	AForm	*form;
	try
	{
		form = makeRobotomyRequestForm(form_name, target);
		std::cout << "Intern creates " << *form << std::endl;
		return form;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		form = makeRobotomyRequestForm(form_name, target);
		std::cout << "Intern creates " << *form << std::endl;
		return form;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		form = makePresidentialPardonForm(form_name, target);
		std::cout << "Intern creates " << *form << std::endl;
		return form;
	}
	catch(const std::exception& e)
	{
	}
	return NULL;
}
