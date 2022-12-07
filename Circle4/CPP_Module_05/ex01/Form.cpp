#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include "Form.hpp"
# include "Color.hpp"

Form::Form ( void )
: _name(), _signed(false), _sign_requirement(0), _execute_requirement(0)
{
	std::cout << BLACK << "[Form] default constructor" << WHITE << std::endl;
}

Form::Form ( const std::string name, const unsigned int sign_requirement, const unsigned int execute_requirement)
: _name(name), _signed(false), _sign_requirement(sign_requirement), _execute_requirement(execute_requirement)
{
	if (_sign_requirement < 1 || _execute_requirement < 1)
		throw Form::GradeTooHighException();
	else if (_sign_requirement > 150 || _execute_requirement > 150)
		throw Form::GradeTooLowException();
	std::cout << BLACK << "[Form] parameter constructor" << WHITE << std::endl;
}

Form::Form ( const Form & other )
: _name(other._name), _signed(other._signed), _sign_requirement(other._sign_requirement), _execute_requirement(other._execute_requirement)
{
	std::cout << BLACK << "[Form] copy constructor" << WHITE << std::endl;
}

Form::~Form ( void )
{
	std::cout << BLACK << "[Form] destructor" << WHITE << std::endl;
}

Form &	Form::operator= ( const Form & other )
{
	if (this != &other)
	{
		//this->_name = other._name;
		this->_signed = other._signed;
		//this->_sign_requirement = other._sign_requirement;
		//this->_execute_requirement = other._execute_requirement;
	}
	return *this;
}

void	Form::beSigned ( const Bureaucrat & bureaucrat )
{
	if (bureaucrat.getGrade() > this->_sign_requirement)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		throw Form::AlreadySignedException();
	this->_signed = true;
}

const std::string	Form::getName ( void ) const
{
	return this->_name;
}

bool	Form::getSigned ( void ) const
{
	return this->_signed;
}

unsigned int	Form::getSignRequirement ( void ) const
{
	return this->_sign_requirement;
}

unsigned int	Form::getExecuteRequirement ( void ) const
{
	return this->_execute_requirement;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Exception: From: Grade Too High";
}


const char * Form::GradeTooLowException::what() const throw()
{
	return "Exception: From: Grade Too Low";
}

const char * Form::AlreadySignedException::what() const throw()
{
	return "Exception: From: Already Signed";
}

std::ostream &	operator<< ( std::ostream & os, const Form & form )
{
	std::cout 
		<< "[Form] " << std::setw(20) << form.getName()
		<< ", : signed : " << std::setw(2) <<  form.getSigned()
		<< ", grade to sign    : " << std::setw(4) <<  form.getSignRequirement()
		<< ", grade to execute : " << std::setw(4) <<  form.getExecuteRequirement();
	return (os);
}
