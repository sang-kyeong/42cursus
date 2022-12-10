#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

typedef enum e_scavtrap_mode
{
	normal_mode = 0,
	gate_keeper_mode,
}	t_scavtrap_mode;

class ScavTrap : public ClapTrap
{

	private:

		t_scavtrap_mode				_mode;

	protected:

	public:

		ScavTrap ( void );
		ScavTrap ( std::string name );
		ScavTrap ( const ScavTrap & other );

		~ScavTrap ( void );

		ScavTrap &	operator= ( const ScavTrap & other );

		void	attack ( const std::string & target );
		void	guardGate ( void );
};

#endif //__CLAPTRAP_H__
