#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void )
 : name("no name"), hit_points(0), energy_points(0), attack_damage(0), alive(true) {
	std::cout << "A ClapTrap is created." << std::endl;
}
ClapTrap::ClapTrap ( const ClapTrap & other )
	 : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage), alive(true) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}
ClapTrap::ClapTrap ( std::string name )
	 : name(name), hit_points(10), energy_points(10), attack_damage(0), alive(true) {
	std::cout << "A ClapTrap " << this->name << " is created." << std::endl;
}
ClapTrap::ClapTrap ( std::string name, int hp, int ep, int damage) : name(name), hit_points(hp), energy_points(ep), attack_damage(damage), alive(true) {
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
	std::cout << "ClapTrap " << this->name <<  " is broken" << std::endl;
}

void	ClapTrap::attack ( const std::string& target ) {
	if (this->alive == false)
		std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " doesn't have enough energy." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
}

void	ClapTrap::takeDamage ( unsigned int amount ) {
	if (this->alive == false)
	{
		std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is attacked, it lose " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
		this->hit_points = 0;
		this->alive = false;
	}
}

void	ClapTrap::beRepaired ( unsigned int amount ) {
	if (this->alive == false)
		std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " doesn't have enough energy." << std::endl;
	else
	{
		int		repaired = -this->hit_points;

		this->hit_points += amount;
		if (this->hit_points > ClapTrap::max_hit_points)
			this->hit_points = ClapTrap::max_hit_points;
		this->energy_points--;
		repaired += this->hit_points;
		std::cout << "ClapTrap " << this->name << " repaired itself, it got " << repaired << " hit points back!" << std::endl;
		if (this->hit_points == ClapTrap::max_hit_points)
			std::cout << "ClapTrap " << this->name << " is get max hit points now!" << std::endl;
	}
}

const std::string &	ClapTrap::getName ( void )	{ return (const std::string &)(this->name); }
int		ClapTrap::getAttackDamage ( void )		{ return (this->attack_damage); }
bool	ClapTrap::isAlive ( void )				{ return (this->alive); }

void	ClapTrap::printInfo ( void ) {
	if (this->alive)
	{
		std::cout << std::endl
			<< "x- "  << this->name << " " << std::setfill('-') << std::setw(38 - this->name.length()) << "x" << std::endl
			<< "|                                        |" << std::endl
			<< "|    ________       Type : CL4P-TP       |" << std::endl
			<< "| &  |\\ (@)/|                            |" << std::endl << std::setfill(' ') 
			<< "| l  | \\__/ |  r    Hit points    : " << std::setw(3) << this->hit_points    << "  |" << std::endl
			<< "| ^--|      |--^    Energy points : "  << std::setw(3) << this->energy_points << "  |" << std::endl
			<< "|     \\____/        Attack Damage : " << std::setw(3) << this->attack_damage << "  |" << std::endl
			<< "|      |#|                               |" << std::endl
			<< "|      |#|                               |" << std::endl
			<< "|                                        |" << std::endl
			<< "x----------------------------------------x" << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl
			<< "x- "  << this->name << " " << std::setfill('-') << std::setw(38 - this->name.length()) << "x" << std::endl
			<< "|                                        |" << std::endl
			<< "|    ________       Type : CL4P-TP       |" << std::endl
			<< "|    |\\ (X)/|                            |" << std::endl << std::setfill(' ') 
			<< "|  --| \\__/ |--    Hit points    : " << std::setw(3) << this->hit_points    << "  |" << std::endl
			<< "|   /|      |\\    Energy points : "  << std::setw(3) << this->energy_points << "  |" << std::endl
			<< "|  l  \\____/ \\       Attack Damage : " << std::setw(3) << this->attack_damage << "  |" << std::endl
			<< "|  &   |#|                               |" << std::endl
			<< "|      |#|                               |" << std::endl
			<< "|                                        |" << std::endl
			<< "x----------------------------------------x" << std::endl << std::endl;
	}
}

// Scav Trap
// x- name ---------------------------------x
// |                                        |
// |    _||*_||_       Type : SC4V-TP       |
// |    |\ (@)/|o__                         |
// |   -| \__/ |  /    Hit points    :  10  |
// |  / |      |_/     Energy points :  10  |
// | |   \____/        Attack Damage :   0  |
// | ^    |#|          Gate Keeper   : OFF  |
// |      |#|                               |
// |                                        |
// x----------------------------------------x
// Scav Trap
// x- name ---------------------------------x
// |                                        |
// |    _||*_||_       Type : SC4V-TP       |
// |    |\(@@)/|                            |
// |   \| \__/ |/      Hit points    :  10  |
// |  / |      | \     Energy points :  10  |
// | &   \____/   &    Attack Damage :   0  |
// |      |##|         Gate Keeper   :  ON  |
// |      |##|                              |
// |                                        |
// x----------------------------------------x
// Frag Trap
// x- name ---------------------------------x
// |                                        |
// |    _|\__/|_       Type : FR4G-TP       |
// | @# |\ (o)/|                            |
// | #@ | \__/ |  /    Hit points    :  10  |
// | ^-\|      |/-^    Energy points :  10  |
// |     \____/        Attack Damage :   0  |
// |      |#|                               |
// |      |#|                               |
// |                                        |
// x----------------------------------------x
// Diamond Trap
// x- name ---------------------------------x
// |                                        |
// |       /^\         Type : Diamond-TP    |
// | $$$  /(o)\                             |
// | $$$ / \_/ \_      Hit points    :  10  |
// | ^-\|/\/\/\/|\     Energy points :  10  |
// |     \_____/  \    Attack Damage :   0  |
// |       |#|                              |
// |       |#|                              |
// |                                        |
// x----------------------------------------x