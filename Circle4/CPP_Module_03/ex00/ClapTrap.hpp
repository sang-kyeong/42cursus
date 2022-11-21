#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

# define IMG_CL4P_TP_LIVE_001	"         ┃          "
# define IMG_CL4P_TP_LIVE_002	"     ┌┬──┸────┬┐    "
# define IMG_CL4P_TP_LIVE_003	"     ││  ╭╭╮  ││    "
# define IMG_CL4P_TP_LIVE_004	"   & │ ╲ ╰╰╯ ╱ │ ┌  "
# define IMG_CL4P_TP_LIVE_005	"   │ │  ╲___╱  │ ├  "
# define IMG_CL4P_TP_LIVE_006	"   └─╲   ╲_╱   ╱─┘  "
# define IMG_CL4P_TP_LIVE_007	"      ╲       ╱     "
# define IMG_CL4P_TP_LIVE_008	"       ╲╭┬─┬╮╱      "
# define IMG_CL4P_TP_LIVE_009	"         │ │        "
# define IMG_CL4P_TP_LIVE_010	"         ╰─╯        "

# define IMG_CL4P_TP_DEAD_001	"         ┃          "
# define IMG_CL4P_TP_DEAD_002	"     ┌┬──┸────┬┐    "
# define IMG_CL4P_TP_DEAD_003	"     ││  ╳ ╳  ││    "
# define IMG_CL4P_TP_DEAD_004	"     │ ╲     ╱ │ ┌─┐"
# define IMG_CL4P_TP_DEAD_005	"     │  ╲___╱  │ ├─┘"
# define IMG_CL4P_TP_DEAD_006	"   ┌─╲   ╲_╱   ╱─┘  "
# define IMG_CL4P_TP_DEAD_007	"   │  ╲       ╱     "
# define IMG_CL4P_TP_DEAD_008	"   &   ╲╭┬─┬╮╱      "
# define IMG_CL4P_TP_DEAD_009	"         │ │        "
# define IMG_CL4P_TP_DEAD_010	"         ╰─╯        "

class ClapTrap
{

private:

	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
	bool		alive;


public:
	static const int	max_hit_points = 10;
	static const int	repair_amount = 2;
	static const int	max_index = 3;

	ClapTrap ( void );
	ClapTrap ( const ClapTrap & other );
	ClapTrap ( std::string name );
	ClapTrap ( std::string name, int hp, int ep, int damage );

	ClapTrap &	operator= (const ClapTrap &other );

	~ClapTrap ( void );

	void	attack ( const std::string& target );
	void	takeDamage ( unsigned int amount );
	void	beRepaired ( unsigned int amount );

	const std::string &	getName ( void ) const ;
	int		getHitPoints ( void ) const ;
	int		getEnergyPoints ( void ) const ;
	int		getAttackDamage ( void ) const ;
	bool	isAlive ( void ) const ;

	void	printOption ( void ) const;
	void	action (int index, ClapTrap &other );
	void	drawPlayer ( std::string screen[] ) const;
	void	drawEnemy ( std::string screen[] ) const;
};

#endif //__CLAPTRAP_H__
