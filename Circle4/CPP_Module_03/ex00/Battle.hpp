#ifndef __BATTLE_H__
# define __BATTLE_H__

#include "ClapTrap.hpp"

typedef enum e_battle_status
{
	fighting = 0,
	player_win,
	enemy_win,
	run,
}	t_battle_status;

class Battle
{

private :

	ClapTrap			&player;
	ClapTrap			&enemy;

	t_battle_status		status;

public :

	Battle ( void );
	Battle ( const Battle & other );
	Battle ( ClapTrap & player, ClapTrap & enemy );

	~Battle ( void );

	Battle &	operator= ( Battle & other );

	void	start ( void );
	void	end ( void );
	void	playerTurn ( void );
	void	enemyTurn ( void );
	bool	isEnd ( void ) const;

// TODO change to private functions
	void	screenDraw ( void );
};

#endif //__BATTLE_H__
