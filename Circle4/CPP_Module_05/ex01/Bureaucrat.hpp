#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
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

	void			signForm ( Form &form );

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