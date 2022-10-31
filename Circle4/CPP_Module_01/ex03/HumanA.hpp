#ifndef __HUMANA_H__
# define __HUMANA_H__

# include <string>
# include "Weapon.hpp"

class	HumanA
{
private:

	std::string	_name;
	Weapon		&_weapon;

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA( void );

	void	attack( void );

};

#endif //__HUMANA_H__
