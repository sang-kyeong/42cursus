#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Color.hpp"

Bureaucrat::Bureaucrat ( void ) : _name(), _grade(150)
{
	std::cout << DARK_GRAY << "[Bureaucrat] default constructor" << WHITE << std::endl;
}

Bureaucrat::Bureaucrat ( const Bureaucrat & other ) : _name(other._name), _grade(other._grade)
{
	std::cout << DARK_GRAY << "[Bureaucrat] copy constructor" << WHITE << std::endl;
}

Bureaucrat::Bureaucrat ( const std::string name, unsigned int grade ) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << DARK_GRAY << "[Bureaucrat] parameter constructor" << WHITE << std::endl;
}

Bureaucrat::~Bureaucrat ( void )
{
	std::cout << DARK_GRAY << "[Bureaucrat] destructor" << WHITE << std::endl;
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
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decreaseGrade ( void )
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm ( Form &form )
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
