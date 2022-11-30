#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	protected:
		
		static const unsigned int	_max_hp = 100;
		static const unsigned int	_max_ep = 50;
		static const unsigned int	_default_dmg = 30;

	public:

		FragTrap ( void );
		FragTrap ( std::string name );
		FragTrap ( const FragTrap & other );

		~FragTrap ( void );

		FragTrap &	operator= ( const FragTrap & other );

		void	attack ( const std::string & target );
		void	takeDamage ( unsigned int amount );
		void	beRepaired ( unsigned int amount) ;
		void	highFivesGuys ( void );

};

#endif //__FRAGTRAP_H__
