#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap
{

private:

	bool	gate_keeper_mode;

public:

	ScavTrap ( void );
	ScavTrap ( const ScavTrap & other );
	ScavTrap ( std::string string );
	ScavTrap ( std::string string, int hp, int ep, int damage );

	ScavTrap &	operator= ( const ScavTrap & other );

	~ScavTrap ( void );

	void	GuardGate ( void );

	void	attack ( const std::string& target );
	void	takeDamage ( unsigned int amount );
	void	beRepaired ( unsigned int amount );

	const std::string &	getName ( void );
	int		getAttackDamage ( void );
	bool	isAlive ( void );

	void	printInfo ( void );
};

#endif //__SCAVTRAP_H__