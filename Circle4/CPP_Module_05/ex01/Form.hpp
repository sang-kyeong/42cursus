#ifndef __FORM_H__
# define __FORM_H__

# ifndef __COLORS__
#  define __COLORS__
#  define NORMAL	"\033[0;30m"
#  define RED		"\033[0;31m"
#  define GREEN		"\033[0;32m"
#  define YELLOW	"\033[0;33m"
#  define BLUE		"\033[0;34m"
#  define MAGENTA	"\033[0;35m"
#  define CYAN		"\033[0;36m"
#  define WHITE		"\033[0;37m"
# endif //__COLORS__

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_sign_requirement;
	const unsigned int	_execute_requirement;

	Form ( void );

protected:
public:
	Form ( const std::string name, const unsigned int sign_requirement, const unsigned int execute_requirement);
	Form ( const Form & other );
	~Form ( void );

	Form &	operator= ( const Form & other );

	void	beSigned ( const Bureaucrat & bureaucrat );

	const std::string	getName ( void ) const;
	bool				getSigned ( void ) const;
	unsigned int		getSignRequirement ( void ) const;
	unsigned int		getExecuteRequirement ( void ) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what () const throw ();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what () const throw ();
	};
};

std::ostream &	operator<< ( std::ostream & os, const Form & form );

#endif //__FORM_H__