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

public:

	ClapTrap ( void );
	ClapTrap ( const ClapTrap & other );
	ClapTrap ( std::string name );

	ClapTrap &	operator= (const ClapTrap &other );

	~ClapTrap ( void );

	void	attack( const std::string& target );
	void	takeDamage ( unsigned int amount );
	void	beRepaired ( unsigned int amount );

};

#endif //__CLAPTRAP_H__
