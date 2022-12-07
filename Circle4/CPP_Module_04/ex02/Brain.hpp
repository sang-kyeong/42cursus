#ifndef __BRAIN_H__
# define __BRAIN_H__

# include <string>
# include "Color.hpp"

class Brain
{
private:
	std::string	_ideas[100];

protected:

public:
	Brain ( void );
	Brain ( const Brain & other );
	
	~Brain ( void );

	Brain &	operator= ( const Brain & other );
};

#endif//__BRAIN_H__