#ifndef __MATERIA_SOURCE__
# define __MATERIA_SOURCE__

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria			*_memory[4];

protected:

public:
	MateriaSource ( void );
	MateriaSource ( const MateriaSource & other );
	MateriaSource &	operator= ( const MateriaSource & other );

	virtual	~MateriaSource ( void );
	virtual void		learnMateria ( AMateria * materia );
	virtual AMateria *	createMateria ( std::string const & type );
};

#endif//__MATERIA_SOURCE__
