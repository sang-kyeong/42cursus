#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) : AForm()
{
	std::cout << GREEN << "[PresidentialPardonForm] default constructor" << WHITE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( const std::string target )
 : AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << GREEN << "[PresidentialPardonForm] name constructor" << WHITE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm & other )
 : AForm(other), _target(other._target)
{
	std::cout << GREEN << "[PresidentialPardonForm] copy constructor" << WHITE << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm ( void )
{
	std::cout << RED << "[PresidentialPardonForm] destructor" << WHITE << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator= ( const PresidentialPardonForm & other )
{
	AForm::operator=(other);
	//this->_target = other._target;
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (executor.getGrade() > this->getExecuteRequirement())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::UnsignedException();
	
	// TODO
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}