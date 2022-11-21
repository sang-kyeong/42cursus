#include <iostream>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"

void	print_dialogue(std::string s1, std::string s2);

ClapTrap::ClapTrap ( void )
 : name("no name"), hit_points(0), energy_points(0), attack_damage(0), alive(true) {
	std::cout << "A ClapTrap is created." << std::endl;
}
ClapTrap::ClapTrap ( const ClapTrap & other )
	 : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage), alive(true) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}
ClapTrap::ClapTrap ( std::string name )
	 : name(name), hit_points(ClapTrap::max_hit_points), energy_points(10), attack_damage(0), alive(true) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}
ClapTrap::ClapTrap ( std::string name, int hp = ClapTrap::max_hit_points, int ep = 10, int damage = 0) : name(name), hit_points(hp), energy_points(ep), attack_damage(damage), alive(true) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}

ClapTrap &	ClapTrap::operator= (const ClapTrap &other ) {
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	this->alive = other.alive;
	return (*this);
}

ClapTrap::~ClapTrap ( void ) {
	std::cout << this->name <<  " is broken" << std::endl;
}

void	ClapTrap::attack ( const std::string& target ) {
	if (this->energy_points == 0)
		print_dialogue(this->name + "(은)는 지쳐서 움직일 수 없다.", "");
	else
	{
		print_dialogue(this->name + "(은)는 " + target + "(을)를 공격했다!", "");
		this->energy_points--;
	}
}

void	ClapTrap::takeDamage ( unsigned int amount ) {
	std::stringstream	ss;
	ss << amount;
	print_dialogue(this->name + "(은)는 " + ss.str() + "의 피해를 입었다.", "");
	this->hit_points -= amount;
	if (this->hit_points <= 0)
	{
		this->hit_points = 0;
		this->alive = false;
	}
}

void	ClapTrap::beRepaired ( unsigned int amount ) {
	if (this->energy_points == 0)
		print_dialogue(this->name + "(은)는 지쳐서 움직일 수 없다.", "");
	else
	{
		int					old_hp;
		std::stringstream	ss;

		old_hp = this->hit_points;
		this->hit_points += amount;
		if (this->hit_points > ClapTrap::max_hit_points)
			this->hit_points = ClapTrap::max_hit_points;
		ss << this->hit_points - old_hp;
		print_dialogue(this->name + "는 " + ss.str() + "의 HP를 복구했다.", "");
		this->energy_points--;
	}
}

const std::string &	ClapTrap::getName ( void ) const	{ return (const std::string &)(this->name); }
int		ClapTrap::getHitPoints ( void ) const			{ return (this->hit_points); }
int		ClapTrap::getEnergyPoints ( void ) const		{ return (this->energy_points); }
int		ClapTrap::getAttackDamage ( void ) const		{ return (this->attack_damage); }
bool	ClapTrap::isAlive ( void ) const				{ return (this->alive); }

void	ClapTrap::printOption ( void ) const
{
	print_dialogue(this->name + "(은)는 무엇을 할까?    " + "1.공격   2. 수리   3. 도망", "");
}

void	ClapTrap::action ( int index, ClapTrap & other )
{
	switch ( index )
	{
	case 1: // attack
		this->attack(other.getName());
		other.takeDamage(this->getAttackDamage());
		break ;
	case 2: // repair
		this->beRepaired(this->repair_amount);
		break ;
	}
}

void	ClapTrap::drawPlayer ( std::string screen[] ) const
{
	for (int i = 2; i < 6; i++)
		screen[i] += "                    ";
	if (this->alive == false)
	{
		screen[6]	+= IMG_CL4P_TP_DEAD_001;
		screen[7]	+= IMG_CL4P_TP_DEAD_002;
		screen[8]	+= IMG_CL4P_TP_DEAD_003;
		screen[9]	+= IMG_CL4P_TP_DEAD_004;
		screen[10]	+= IMG_CL4P_TP_DEAD_005;
		screen[11]	+= IMG_CL4P_TP_DEAD_006;
		screen[12]	+= IMG_CL4P_TP_DEAD_007;
		screen[13]	+= IMG_CL4P_TP_DEAD_008;
		screen[14]	+= IMG_CL4P_TP_DEAD_009;
		screen[15]	+= IMG_CL4P_TP_DEAD_010;
	}
	else
	{
		screen[6]	+= IMG_CL4P_TP_LIVE_001;
		screen[7]	+= IMG_CL4P_TP_LIVE_002;
		screen[8]	+= IMG_CL4P_TP_LIVE_003;
		screen[9]	+= IMG_CL4P_TP_LIVE_004;
		screen[10]	+= IMG_CL4P_TP_LIVE_005;
		screen[11]	+= IMG_CL4P_TP_LIVE_006;
		screen[12]	+= IMG_CL4P_TP_LIVE_007;
		screen[13]	+= IMG_CL4P_TP_LIVE_008;
		screen[14]	+= IMG_CL4P_TP_LIVE_009;
		screen[15]	+= IMG_CL4P_TP_LIVE_010;
	}
}

void	ClapTrap::drawEnemy ( std::string screen[] ) const
{
	if (this->alive == false)
	{
		screen[2]	+= IMG_CL4P_TP_DEAD_001;
		screen[3]	+= IMG_CL4P_TP_DEAD_002;
		screen[4]	+= IMG_CL4P_TP_DEAD_003;
		screen[5]	+= IMG_CL4P_TP_DEAD_004;
		screen[6]	+= IMG_CL4P_TP_DEAD_005;
		screen[7]	+= IMG_CL4P_TP_DEAD_006;
		screen[8]	+= IMG_CL4P_TP_DEAD_007;
		screen[9]	+= IMG_CL4P_TP_DEAD_008;
		screen[10]	+= IMG_CL4P_TP_DEAD_009;
		screen[11]	+= IMG_CL4P_TP_DEAD_010;
	}
	else
	{
		screen[2]	+= IMG_CL4P_TP_LIVE_001;
		screen[3]	+= IMG_CL4P_TP_LIVE_002;
		screen[4]	+= IMG_CL4P_TP_LIVE_003;
		screen[5]	+= IMG_CL4P_TP_LIVE_004;
		screen[6]	+= IMG_CL4P_TP_LIVE_005;
		screen[7]	+= IMG_CL4P_TP_LIVE_006;
		screen[8]	+= IMG_CL4P_TP_LIVE_007;
		screen[9]	+= IMG_CL4P_TP_LIVE_008;
		screen[10]	+= IMG_CL4P_TP_LIVE_009;
		screen[11]	+= IMG_CL4P_TP_LIVE_010;
	}
	for (int i = 12; i < 16; i++)
		screen[i] += "                    ";
}
