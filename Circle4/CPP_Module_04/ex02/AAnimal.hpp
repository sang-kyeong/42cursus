#ifndef __AANIMAL_H__
# define __AANIMAL_H__

# include <string>
# include "Color.hpp"

class AAnimal
{
private:

protected:
	std::string		type;

public:
	AAnimal ( void );
	AAnimal ( std::string type );
	AAnimal ( const AAnimal & other );

	virtual ~AAnimal ( void );

	AAnimal &	operator= ( const AAnimal & other );

	const std::string &	getType ( void ) const;
	virtual void	makeSound ( void ) const = 0;

};

#endif //__AANIMAL_H__
