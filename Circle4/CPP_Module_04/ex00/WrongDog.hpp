#ifndef __WRONG_DOG_H__
# define __WRONG_DOG_H__

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{

	public:

		WrongDog ( void );
		WrongDog ( const WrongDog & other );

		~WrongDog ( void );

		WrongDog &	operator= ( const WrongDog & other );

		void	makeSound ( void ) const;

};

#endif //__WRONG_DOG_H__
