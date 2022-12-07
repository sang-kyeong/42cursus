#ifndef __WRONG_ANIMAL_H__
# define __WRONG_ANIMAL_H__

# include <string>
# include "Color.hpp"

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
