#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

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
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	static const unsigned int		_highest_grade = 1;
	static const unsigned int		_lowest_grade = 150;

	const std::string	_name;
	unsigned int		_grade;
protected:

public:
	Bureaucrat ( void );
	Bureaucrat ( const Bureaucrat & other );
	Bureaucrat ( const std::string name, unsigned int grade );
	~Bureaucrat ( void );

	Bureaucrat &	operator= ( const Bureaucrat & other );

	void			increaseGrade ( void );
	void			decreaseGrade ( void );

	void			signForm ( AForm &form );
	void			executeForm( AForm const & form );

	const std::string	getName ( void ) const;
	unsigned int		getGrade ( void ) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

std::ostream &	operator<< ( std::ostream & os, const Bureaucrat & bureaucrat );

#endif //__BUREAUCRAT_H__