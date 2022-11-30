#ifndef __CAT_H__
# define __CAT_H__

# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat ( void );
		Cat ( const Cat & other );

		~Cat ( void );

		Cat &	operator= ( const Cat & other );
		
		void	makeSound ( void ) const;

};

#endif //__CAT_H__
