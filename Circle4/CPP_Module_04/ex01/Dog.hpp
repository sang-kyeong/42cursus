#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

	private:
		Brain	*_brain;

	public:

		Dog ( void );
		Dog ( const Dog & other );

		~Dog ( void );

		Dog &	operator= ( const Dog & other );

		void	makeSound ( void ) const;

};

#endif //__DOG_H__
