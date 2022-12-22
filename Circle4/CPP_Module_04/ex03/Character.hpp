#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include <string.h>
# include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter
{
private:
	std::string			_name;
	AMateria			*_inventory[4];

protected:

public:
	Character ( void );
	Character ( const Character & other );
	Character ( std::string name );
	~Character ( void );

	Character &	operator= ( const Character & other );

	std::string const &	getName ( void ) const;
	void				equip ( AMateria *m );
	void				unequip ( int idx );
	void				use ( int idx, ICharacter & target );
};

#endif//__CHARACTER_H__
