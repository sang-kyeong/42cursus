#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

Bureaucrat::Bureaucrat ( void ) : _name(), _grade(Bureaucrat::_lowest_grade)
{
	std::cout << BLACK << "[Bureaucrat] default constructor" << WHITE << std::endl;
}

Bureaucrat::Bureaucrat ( const Bureaucrat & other ) : _name(other._name), _grade(other._grade)
{
	std::cout << BLACK << "[Bureaucrat] copy constructor" << WHITE << std::endl;
}

Bureaucrat::Bureaucrat ( const std::string name, unsigned int grade ) : _name(name), _grade(grade)
{
	if (this->_grade < Bureaucrat::_highest_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::_lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	std::cout << BLACK << "[Bureaucrat] parameter constructor" << WHITE << std::endl;
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

void	Bureaucrat::signForm ( AForm &form )
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << WHITE << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << WHITE << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form )
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->_name << " executed " << form.getName() << WHITE << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << WHITE << std::endl;
	}
}

const std::string	Bureaucrat::getName ( void ) const
{
	return this->_name;
}

unsigned int		Bureaucrat::getGrade ( void ) const
{
	return this->_grade;
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
