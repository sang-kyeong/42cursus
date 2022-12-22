#ifndef __I_CHARACTER_H__
# define __I_CHARACTER_H__

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
private:

protected:
	ICharacter ( void );
	ICharacter ( const ICharacter & other );

	ICharacter &	operator= ( const ICharacter & other );

public:
	virtual ~ICharacter ( void );
	virtual std::string const &	getName ( void ) const = 0;
	virtual void				equip ( AMateria *m ) = 0;
	virtual void				unequip ( int idx ) = 0;
	virtual void				use ( int idx, ICharacter & target ) = 0;
};

#endif//__I_CHARACTER_H__
