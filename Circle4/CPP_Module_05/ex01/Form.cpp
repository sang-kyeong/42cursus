#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

Form::Form ( void )
: _name(), _signed(false), _sign_requirement(0), _execute_requirement(0)
{
	std::cout << GREEN << "[Form] default constructor" << WHITE << std::endl;
}

Form::Form ( const std::string name, const unsigned int sign_requirement, const unsigned int execute_requirement)
: _name(name), _signed(false), _sign_requirement(sign_requirement), _execute_requirement(execute_requirement)
{
	if (_sign_requirement < 1 || _execute_requirement < 1)
		throw Form::GradeTooHighException();
	else if (_sign_requirement > 150 || _execute_requirement > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN << "[Form] parameter constructor" << WHITE << std::endl;
}

Form::Form ( const Form & other )
: _name(other._name), _signed(other._signed), _sign_requirement(other._sign_requirement), _execute_requirement(other._execute_requirement)
{
	std::cout << GREEN << "[Form] copy constructor" << WHITE << std::endl;
}

Form::~Form ( void )
{
	std::cout << RED << "[Form] destructor" << WHITE << std::endl;
}

Form &	Form::operator= ( const Form & other )
{
	//this->_name = other._name;
	this->_signed = other._signed;
	//this->_sign_requirement = other._sign_requirement;
	//this->_execute_requirement = other._execute_requirement;
	return *this;
}

void	Form::beSigned ( const Bureaucrat & bureaucrat )
{
	if (bureaucrat.getGrade() > this->_sign_requirement)
		throw Form::GradeTooLowException();
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
	return "Grade Too High";
}


const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

std::ostream &	operator<< ( std::ostream & os, const Form & form )
{
	std::cout << "[Form] " << form.getName()
		<< ", : signed : " <<  form.getSigned()
		<< ", grade to sign    : " <<  form.getSignRequirement()
		<< ", grade to execute : " <<  form.getExecuteRequirement();
	return (os);
}
