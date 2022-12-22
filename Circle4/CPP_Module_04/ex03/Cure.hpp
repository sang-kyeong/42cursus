#ifndef __CURE_H__
# define __CURE_H__

# include <string.h>
# include "AMateria.hpp"

class Cure : public AMateria
{
private:

protected:

public:
	Cure ( void );
	Cure ( const Cure & other );
	~Cure ( void );

	Cure &	operator= ( const Cure & other );

	AMateria*	clone ( void ) const;
	void		use ( ICharacter & target );
};

#endif//__CURE_H__
