#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

class ClapTrap
{

	protected:
		
		static const unsigned int	_max_hp = 10;
		static const unsigned int	_max_ep = 10;
		static const unsigned int	_default_dmg = 0;

		std::string					_name;
		unsigned int				_hit_points;
		unsigned int				_energe_points;
		unsigned int				_attack_damage;

		ClapTrap ( std::string name, unsigned int hp, unsigned int ep, unsigned int dmg);

	public:

		ClapTrap ( void );
		ClapTrap ( std::string name );
		ClapTrap ( const ClapTrap & other );

		~ClapTrap ( void );

		ClapTrap &	operator= ( const ClapTrap & other );

		void	attack ( const std::string & target );
		void	takeDamage ( unsigned int amount );
		void	beRepaired ( unsigned int amount );

		const std::string &	getName (void);
		unsigned int	getAttackDamage ( void );

};

#endif //__CLAPTRAP_H__
