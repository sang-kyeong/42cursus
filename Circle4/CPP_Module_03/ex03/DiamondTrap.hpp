#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

	protected:
		
		static const unsigned int	_max_hp = 100;
		static const unsigned int	_max_ep = 50;
		static const unsigned int	_default_dmg = 30;

	public:

		DiamondTrap ( void );
		DiamondTrap ( std::string name );
		DiamondTrap ( const DiamondTrap & other );

		~DiamondTrap ( void );

		DiamondTrap &	operator= ( const DiamondTrap & other );

		void	attack ( const std::string & target );
		void	takeDamage ( unsigned int amount );
		void	beRepaired ( unsigned int amount );
		void	highFivesGuys ( void );

};

#endif //__DIAMONDTRAP_H__
