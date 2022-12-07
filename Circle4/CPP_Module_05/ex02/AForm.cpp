#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include "AForm.hpp"
#include "Color.hpp"

AForm::AForm ( void )
: _name(), _signed(false), _sign_requirement(0), _execute_requirement(0)
{
	std::cout << BLACK << "[AForm] default constructor" << WHITE << std::endl;
}

AForm::AForm ( const std::string name, const unsigned int sign_requirement, const unsigned int execute_requirement)
: _name(name), _signed(false), _sign_requirement(sign_requirement), _execute_requirement(execute_requirement)
{
	if (_sign_requirement < 1 || _execute_requirement < 1)
		throw AForm::GradeTooHighException();
	else if (_sign_requirement > 150 || _execute_requirement > 150)
		throw AForm::GradeTooLowException();
	std::cout << BLACK << "[AForm] parameter constructor" << WHITE << std::endl;
}

AForm::AForm ( const AForm & other )
: _name(other._name), _signed(other._signed), _sign_requirement(other._sign_requirement), _execute_requirement(other._execute_requirement)
{
	std::cout << BLACK << "[AForm] copy constructor" << WHITE << std::endl;
}

AForm::~AForm ( void )
{
	std::cout << BLACK << "[AForm] destructor" << WHITE << std::endl;
}

AForm &	AForm::operator= ( const AForm & other )
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

void	AForm::beSigned ( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > this->_sign_requirement)
		throw AForm::GradeTooLowException();
	else if (this->_signed == true)
		throw AForm::AlreadySignedException();
	this->_signed = true;
}

const std::string	AForm::getName ( void ) const
{
	return this->_name;
}

bool	AForm::getSigned ( void ) const
{
	return this->_signed;
}

unsigned int	AForm::getSignRequirement ( void ) const
{
	return this->_sign_requirement;
}

unsigned int	AForm::getExecuteRequirement ( void ) const
{
	return this->_execute_requirement;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Exception: AFrom: Grade Too High";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Exception: AFrom: Grade Too Low";
}

const char * AForm::AlreadySignedException::what() const throw()
{
	return "Exception: AFrom: Already Signed";
}

const char * AForm::UnsignedException::what() const throw()
{
	return "Exception: AFrom: Unsigned";
}

const char * AForm::IOException::what() const throw()
{
	return "Exception: AFrom: IO failed";
}

std::ostream &	operator<< ( std::ostream & os, const AForm & form )
{
	std::cout 
		<< "[Form] " << std::setw(20) << form.getName()
		<< ", : signed : " << std::setw(2) <<  form.getSigned()
		<< ", grade to sign    : " << std::setw(4) <<  form.getSignRequirement()
		<< ", grade to execute : " << std::setw(4) <<  form.getExecuteRequirement();
	return (os);
}
