#ifndef __ICE_H__
# define __ICE_H__

# include <string.h>
# include "AMateria.hpp"

class Ice : public AMateria
{
private:

protected:

public:
	Ice ( void );
	Ice ( const Ice & other );
	~Ice ( void );

	Ice &	operator= ( const Ice & other );

	AMateria*	clone ( void ) const;
	void		use ( ICharacter & target );
};

#endif//__ICE_H__
