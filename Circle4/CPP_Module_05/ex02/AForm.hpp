#ifndef __AFORM_H__
# define __AFORM_H__

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

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_sign_requirement;
	const unsigned int	_execute_requirement;

protected:
	AForm ( void );

public:
	AForm ( const std::string name, const unsigned int sign_requirement, const unsigned int execute_requirement);
	AForm ( const AForm & other );
	virtual ~AForm ( void );

	AForm &	operator= ( const AForm & other );

	void	beSigned ( Bureaucrat const & bureaucrat );
	virtual void	execute( Bureaucrat const & executor) const = 0;

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
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char * what () const throw ();
	};
	class UnsignedException : public std::exception
	{
	public:
		virtual const char * what () const throw ();
	};
	class IOException : public std::exception
	{
	public:
		virtual const char * what () const throw ();
	};
};

std::ostream &	operator<< ( std::ostream & os, const AForm & AForm );

#endif //__AFORM_H__