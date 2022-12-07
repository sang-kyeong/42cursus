#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

Bureaucrat::Bureaucrat ( void ) : _name(), _grade(150)
{
	std::cout << BLACK << "[Bureaucrat] Default constructor" << WHITE << std::endl;
}

Bureaucrat::Bureaucrat ( const Bureaucrat & other ) : _name(other._name), _grade(other._grade)
{
	std::cout << BLACK << "[Bureaucrat] Copy constructor" << WHITE << std::endl;
}

Bureaucrat::Bureaucrat ( const std::string name, unsigned int grade ) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
	{
		this->_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->_grade > 150)
	{
		this->_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << BLACK << "[Bureaucrat] Name Grade constructor" << WHITE << std::endl;
}

Bureaucrat::~Bureaucrat ( void )
{
	std::cout << BLACK << "[Bureaucrat] destructor" << WHITE << std::endl;
}


Bureaucrat &	Bureaucrat::operator= ( const Bureaucrat & other )
{
	if (this != &other)
	{
		// this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

const std::string	Bureaucrat::getName ( void ) const
{
	return this->_name;
}

unsigned int		Bureaucrat::getGrade ( void ) const
{
	return this->_grade;
}

void	Bureaucrat::increaseGrade ( void )
{
	if (this->_grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void	Bureaucrat::decreaseGrade ( void )
{
	if (this->_grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Bureaucrat: Grade Too High";
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Bureaucrat: Grade Too Low";
}

std::ostream &	operator<< ( std::ostream & os, const Bureaucrat & bureaucrat )
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " <<  bureaucrat.getGrade() << ".";
	return os;
}
