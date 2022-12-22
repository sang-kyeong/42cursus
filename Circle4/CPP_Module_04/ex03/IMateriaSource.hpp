#ifndef __I_MATERIA_SOURCE__
# define __I_MATERIA_SOURCE__

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
private:

protected:
	IMateriaSource ( void );
	IMateriaSource ( const IMateriaSource & other );

public:
	IMateriaSource &	operator= ( const IMateriaSource & other );

	virtual	~IMateriaSource ( void );
	virtual void		learnMateria ( AMateria * materia ) = 0;
	virtual AMateria *	createMateria ( std::string const & type ) = 0;
};

#endif//__I_MATERIA_SOURCE__
