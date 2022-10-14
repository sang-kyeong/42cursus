#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>

class Zombie
{

public:

	Zombie( void );
	~Zombie( void );

	void	set_name(std::string name);
	void	announce( void );

private:
	std::string		name;
};

#endif