#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

#include <string>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie ( void );
	Zombie (std::string name);
	~Zombie ( void );

	void	set_name(std::string);
	void	anounce ( void );
};

#endif //__ZOMBIE_H__
