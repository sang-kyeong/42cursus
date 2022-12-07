#ifndef __WRONG_ANIMAL_H__
# define __WRONG_ANIMAL_H__

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

class WrongAnimal
{
private:

protected:
	std::string		type;

public:
	WrongAnimal ( void );
	WrongAnimal ( std::string type );
	WrongAnimal ( const WrongAnimal & other );

	~WrongAnimal ( void );

	WrongAnimal &	operator= ( const WrongAnimal & other );

	const std::string &	getType ( void ) const;
	void	makeSound ( void ) const;

};

#endif //__WRONG_ANIMAL_H__
