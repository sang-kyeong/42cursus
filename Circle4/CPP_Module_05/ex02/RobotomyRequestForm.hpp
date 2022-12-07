#ifndef __ROBOTOMY_REQUEST_FORM_H__
# define __ROBOTOMY_REQUEST_FORM_H__

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
private:
	const std::string	_target;

	RobotomyRequestForm ( void );

protected:
public:
	RobotomyRequestForm ( const std::string target );
	RobotomyRequestForm ( const RobotomyRequestForm & other );
	~RobotomyRequestForm ( void );

	RobotomyRequestForm &	operator= ( const RobotomyRequestForm & other );

	void	execute( Bureaucrat const & executor ) const;
};

#endif//__ROBOTOMY_REQUEST_FORM_H__