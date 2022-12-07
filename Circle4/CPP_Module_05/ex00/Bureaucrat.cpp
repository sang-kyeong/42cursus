#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) : _name(), _grade(Bureaucrat::_lowest_grade)
{
	std::cout << GREEN << "[Bureaucrat] Default constructor" << NORMAL << std::endl;
}

Bureaucrat::Bureaucrat ( const Bureaucrat & other ) : _name(other._name), _grade(other._grade)
{
	std::cout << GREEN << "[Bureaucrat] Copy constructor" << NORMAL << std::endl;
}

Bureaucrat::Bureaucrat ( const std::string name, unsigned int grade ) : _name(name), _grade(grade)
{
	if (this->_grade < Bureaucrat::_highest_grade)
	{
		this->_grade = _highest_grade;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->_grade > Bureaucrat::_lowest_grade)
	{
		this->_grade = _lowest_grade;
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << GREEN << "[Bureaucrat] Name Grade constructor" << NORMAL << std::endl;
}

Bureaucrat::~Bureaucrat ( void )
{
	std::cout << RED << "[Bureaucrat] destructor" << NORMAL << std::endl;
}


Bureaucrat &	Bureaucrat::operator= ( const Bureaucrat & other )
{
	// this->_name = other._name;
	this->_grade = other._grade;
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
	if (this->_grade <= Bureaucrat::_highest_grade)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void	Bureaucrat::decreaseGrade ( void )
{
	if (this->_grade >= Bureaucrat::_lowest_grade)
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
	return (os);
}
