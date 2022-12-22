#ifndef __A_MATERIA_H__
# define __A_MATERIA_H__

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	std::string			_type;

protected:
	AMateria ( void );
	AMateria ( const AMateria & other );

public:
	AMateria ( std::string const & type );

	virtual ~AMateria ( void );

	AMateria &	operator= ( const AMateria & other );

	std::string const &	getType ( void ) const; // Return the Materia type

	virtual AMateria*	clone ( void ) const = 0;
	virtual void		use ( ICharacter & target );
};

#endif//__A_MATERIA_H__
