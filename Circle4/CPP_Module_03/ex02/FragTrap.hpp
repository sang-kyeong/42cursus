#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	protected:

	public:

		FragTrap ( void );
		FragTrap ( std::string name );
		FragTrap ( const FragTrap & other );

		~FragTrap ( void );

		FragTrap &	operator= ( const FragTrap & other );

		void	highFivesGuys ( void );

};

#endif //__FRAGTRAP_H__
