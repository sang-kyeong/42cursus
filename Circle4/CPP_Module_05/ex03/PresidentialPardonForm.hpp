#ifndef __PRESIDENTIAL_PARDON_FORM_H__
# define __PRESIDENTIAL_PARDON_FORM_H__

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	const std::string	_target;

	PresidentialPardonForm ( void );

protected:
public:
	PresidentialPardonForm ( const std::string target );
	PresidentialPardonForm ( const PresidentialPardonForm & other );
	~PresidentialPardonForm ( void );

	PresidentialPardonForm &	operator= ( const PresidentialPardonForm & other );

	void	execute( Bureaucrat const & executor ) const;
};

#endif//__PRESIDENTIAL_PARDON_FORM_H__