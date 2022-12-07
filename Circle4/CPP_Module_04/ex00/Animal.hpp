#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# ifndef __COLOR__
#  define __COLOR__
#  define NORMAL	"\033[0;30m"
#  define RED		"\033[0;31m"
#  define GREEN		"\033[0;32m"
#  define YELLOW	"\033[0;33m"
#  define BLUE		"\033[0;34m"
#  define MAGENTA	"\033[0;35m"
#  define CYAN		"\033[0;36m"
#  define WHITE		"\033[0;37m"
# endif //__COLOR__

# include <string>

class Animal
{
private:

protected:
	std::string		type;

public:
	Animal ( void );
	Animal ( std::string type );
	Animal ( const Animal & other );

	virtual ~Animal ( void );

	Animal &	operator= ( const Animal & other );

	const std::string &	getType ( void ) const;
	virtual void	makeSound ( void ) const;

};

#endif //__ANIMAL_H__
