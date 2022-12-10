#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

class ClapTrap
{

	protected:

		std::string					_name;
		unsigned int				_hit_points;
		unsigned int				_energy_points;
		unsigned int				_attack_damage;
	
		ClapTrap ( const std::string name, unsigned int hp, unsigned int ep, unsigned int dmg );

	public:

		ClapTrap ( void );
		ClapTrap ( std::string name );
		ClapTrap ( const ClapTrap & other );

		virtual ~ClapTrap ( void );

		ClapTrap &	operator= ( const ClapTrap & other );

		virtual void	attack ( const std::string & target );
		void	takeDamage ( unsigned int amount );
		void	beRepaired ( unsigned int amount );

		const std::string &	getName (void) const;
		unsigned int		getHitPoints ( void ) const;
		unsigned int		getEnergyPoints ( void ) const;
		unsigned int		getAttackDamage ( void ) const;

		void		getName ( const std::string & name );
		void		getHitPoints ( unsigned int points );
		void		getEnergyPoints ( unsigned int points );
		void		getAttackDamage ( unsigned int points );

		void		showStatus ( void );

};

#endif //__CLAPTRAP_H__
