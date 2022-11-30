#ifndef __WRONG_CAT_H__
# define __WRONG_CAT_H__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat ( void );
		WrongCat ( const WrongCat & other );

		~WrongCat ( void );

		WrongCat &	operator= ( const WrongCat & other );
		
		void	makeSound ( void ) const;

};

#endif //__WRONG_CAT_H__
