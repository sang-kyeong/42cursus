#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

typedef enum e_scavtrap_mode
{
	normal_mode = 0,
	gate_keeper_mode,
}	t_scavtrap_mode;

class ScavTrap : protected ClapTrap
{

	protected:
		
		static const unsigned int	_max_hp = 100;
		static const unsigned int	_max_ep = 50;
		static const unsigned int	_default_dmg = 20;

		t_scavtrap_mode				_mode;

	public:

		ScavTrap ( void );
		ScavTrap ( std::string name );
		ScavTrap ( const ScavTrap & other );

		~ScavTrap ( void );

		ScavTrap &	operator= ( const ScavTrap & other );

		void	attack ( const std::string & target );
		void	takeDamage ( unsigned int amount );
		void	beRepaired ( unsigned int amount );
		void	guardGate ( void );

		const std::string &	getName (void);
		unsigned int	getAttackDamage ( void );

};

#endif //__CLAPTRAP_H__
