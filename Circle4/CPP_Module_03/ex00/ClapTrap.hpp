#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

class ClapTrap
{

private:

	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
	bool		alive;

	static const int	max_hit_points = 20;

public:

	ClapTrap ( void );
	ClapTrap ( const ClapTrap & other );
	ClapTrap ( std::string name );
	ClapTrap ( std::string name, int hp, int ep, int damage );

	ClapTrap &	operator= (const ClapTrap &other );

	~ClapTrap ( void );

	void	attack( const std::string& target );
	void	takeDamage ( unsigned int amount );
	void	beRepaired ( unsigned int amount );

	const std::string &	getName ( void );
	int		getAttackDamage ( void );
	bool	isAlive ( void );

	void	printInfo ( void );
	// Clap Trap
	// x- name ---------------------------------x
	// |                                        |
	// |    ________       Type : CL4P-TP       |
	// | &  |\ (@)/|                            |
	// | l  | \__/ |  r    Hit points    :  10  |
	// | ^--|      |--^    Energy points :  10  |
	// |     \____/        Attack Damage :   0  |
	// |      |#|                               |
	// |      |#|                               |
	// |                                        |
	// x----------------------------------------x

};

#endif //__CLAPTRAP_H__
