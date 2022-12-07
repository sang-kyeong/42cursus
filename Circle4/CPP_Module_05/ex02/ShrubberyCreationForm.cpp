#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm ( void ) : AForm()
{
	std::cout << GREEN << "[ShrubberyCreationForm] default constructor" << WHITE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const std::string target )
 : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << GREEN << "[ShrubberyCreationForm] name constructor" << WHITE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm & other )
 : AForm(other), _target(other._target)
{
	std::cout << GREEN << "[ShrubberyCreationForm] copy constructor" << WHITE << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
	std::cout << RED << "[ShrubberyCreationForm] destructor" << WHITE << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator= ( const ShrubberyCreationForm & other )
{
	AForm::operator=(other);
	//this->_target = other._target;
	return *this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (executor.getGrade() > this->getExecuteRequirement())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::UnsignedException();
	
	// TODO
	std::ofstream	os(this->_target + "_shrubbery");
	if (os.fail() | !os.is_open())
		throw AForm::IOException();
	os << SHRUBBERY_ASCII_TREE;
	if (os.fail())
		throw AForm::IOException();
	os.close();
}
