#ifndef __INTERN_H__
# define __INTERN_H__

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm *	makeShrubberyCreationForm( const std::string form_name, const std::string target ) const;
	AForm *	makeRobotomyRequestForm( const std::string form_name, const std::string target ) const;
	AForm *	makePresidentialPardonForm( const std::string form_name, const std::string target ) const;

protected:

public:
	Intern ( void );
	Intern ( const Intern & other );

	~Intern ( void );

	Intern &	operator= ( const Intern & other );

	AForm *	makeForm ( const std::string form_name, const std::string target ) const;

};

#endif//__INTERN_H__
