#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <string>
# include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;

	Bureaucrat ( void );

protected:

public:
	Bureaucrat ( const Bureaucrat & other );
	Bureaucrat ( const std::string name, unsigned int grade );
	~Bureaucrat ( void );

	Bureaucrat &	operator= ( const Bureaucrat & other );

	const std::string	getName ( void ) const;
	unsigned int		getGrade ( void ) const;

	void				increaseGrade ( void );
	void				decreaseGrade ( void );

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