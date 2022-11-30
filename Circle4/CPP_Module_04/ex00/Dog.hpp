#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog ( void );
		Dog ( const Dog & other );

		~Dog ( void );

		Dog &	operator= ( const Dog & other );

		void	makeSound ( void ) const;

};

#endif //__DOG_H__
