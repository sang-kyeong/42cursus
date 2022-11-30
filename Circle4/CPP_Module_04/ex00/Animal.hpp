#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <string>

class Animal
{

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
