#ifndef __SHRUBBERY_CREATION_FORM_H__
# define __SHRUBBERY_CREATION_FORM_H__

#include "AForm.hpp"

# define SHRUBBERY_ASCII_TREE "     .{{}}}}}}.\n    {{{{{{(`)}}}.\n   {{{(`)}}}}}}}}}\n  }}}}}}}}}{{(`){{{\n  }}}}{{{{(`)}}{{{{\n {{{(`)}}}}}}}{}}}}}\n{{{{{{{{(`)}}}}}}}}}}\n{{{{{{{}{{{{(`)}}}}}}\n {{{{{(`)   {{{{(`)}'\n  `\"\"'\" |   | \"'\"'`\n  (`)  /     \\n ~~~~~~~~~~~~~~~~~~~"

class	ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;

	ShrubberyCreationForm ( void );

protected:
public:
	ShrubberyCreationForm ( const std::string target );
	ShrubberyCreationForm ( const ShrubberyCreationForm & other );
	~ShrubberyCreationForm ( void );

	ShrubberyCreationForm &	operator= ( const ShrubberyCreationForm & other );

	void	execute( Bureaucrat const & executor ) const;
};

#endif//__SHRUBBERY_CREATION_FORM_H__