#include <iostream>
#include <sstream>
#include <iomanip>
#include "Battle.hpp"

#include <unistd.h>

int		get_player_input ( int max_index );
void	clear_dialogue ( void );
void	print_dialogue( std::string dialogue1, std::string dialogue2 );

// Battle::Battle ( void ) : player(ClapTrap()), enemy(ClapTrap()) {}
Battle::Battle ( const Battle & other ) : player(other.player), enemy(other.enemy), status(other.status) {}
Battle::Battle ( ClapTrap & player, ClapTrap & enemy ) : player(player), enemy(enemy), status(fighting) {}

Battle::~Battle ( void ) {}

Battle &	Battle::operator= ( Battle & other ) {
	this->player = other.player;
	this->enemy = other.enemy;
	this->status = other.status;
	return (*this);
}


void	Battle::start ( void ) {
	std::srand(static_cast<unsigned int>(std::time(0)));

	this->screenDraw();

	std::cout << std::endl << std::endl << "\r\033[2A";
	usleep(500000);
	print_dialogue("야생의 SC4V-TP이 튀어나왔다!", "");
	usleep(2000000);
	clear_dialogue();
}

void	Battle::end ( void ) {
	std::string	buf;

	switch (this->status)
	{
	case player_win:
		print_dialogue("신난다 !", this->enemy.getName() + "(을)를 쓰러트렸다!");
		break ;
	case enemy_win:
		print_dialogue(this->player.getName() + "(은)는 쓰러졌다.", this->player.getName() + "(은)는 눈앞이 깜깜해졌다.");
		break ;
	case run:
		print_dialogue(this->player.getName() + "(은)는 무사히 도망쳤다.", "");
		break ;
	default:
		;
	}
	std::cout << "\033[2BEnter를 눌러 종료." << std::endl;
	std::getline(std::cin, buf);
}

void	Battle::playerTurn ( void ) {
	int		index;

	this->player.printOption();
	std::cout << "\r\033[1B";
	index = get_player_input(player.max_index);
	std::cout << "\r\033[2A";
	if (index == player.max_index) // run
		this->status = run;
	else
	{
		player.action(index, this->enemy);
		std::cout << "\r\033[17A";
		this->screenDraw();
		if (enemy.isAlive() == false)
			this->status = player_win;
	}
}

void	Battle::enemyTurn ( void ) {
	int		index;

	index = (std::rand() % enemy.max_index - 1) + 1;
	this->enemy.action(index, this->player);
	std::cout << "\r\033[17A";
	screenDraw();
	if (player.isAlive() == false)
	{
		this->status = enemy_win;
		return ;
	}
}

bool	Battle::isEnd ( void ) const { return (this->status != fighting); }

void	Battle::screenDraw ( void ) {
	std::string screen[17];
	std::stringstream ss_name, ss_hp, ss_ep, ss_damage;

	screen[0]	= "┌─ Trap Monster ───────────────────────────────────────────────────────────────┐";
	screen[1]	= "│                                                                              │";

	for (int i = 2; i < 16; i++)
		screen[i] += "│ ";
	player.drawPlayer(screen);
	ss_name << std::setw(8) << this->enemy.getName();
	ss_hp << std::setw(8) << this->enemy.getHitPoints();
	ss_ep << std::setw(8) << this->enemy.getEnergyPoints();
	ss_damage << std::setw(8) << this->enemy.getAttackDamage();

	screen[2]	+= "       ┌─────────────────── SC4V-TP ";
	screen[3]	+= "       │  name          " + ss_name.str()   + "  │ ";
	screen[4]	+= "       │  HP            " + ss_hp.str()     + "  │ ";
	screen[5]	+= "       │  EP            " + ss_ep.str()     + "  │ ";
	screen[6]	+= "       │  Power         " + ss_damage.str() + "  │ ";
	screen[7]	+= "       └──────────────────────────┘ ";
	screen[8]	+= "                                    ";
	
	ss_name.str("");
	ss_hp.str("");
	ss_ep.str("");
	ss_damage.str("");
	ss_name << std::setw(8) << this->player.getName();
	ss_hp << std::setw(8) << this->player.getHitPoints();
	ss_ep << std::setw(8) << this->player.getEnergyPoints();
	ss_damage << std::setw(8) << this->player.getAttackDamage();

	screen[9]	+= " SC4V-TP ───────────────────┐       ";
	screen[10]	+= " │  name          " + ss_name.str()   + "  │       ";
	screen[11]	+= " │  HP            " + ss_hp.str()     + "  │       ";
	screen[12]	+= " │  EP            " + ss_ep.str()     + "  │       ";
	screen[13]	+= " │  Power         " + ss_damage.str() + "  │       ";
	screen[14]	+= " └──────────────────────────┘       ";
	screen[15]	+= "                                    ";
	enemy.drawEnemy(screen);
	for (int i = 2; i < 16; i++)
		screen[i] += " │";

	screen[16]	= "└──────────────────────────────────────────────────────────────────────────────┘";

	for (int i = 0; i < 17; i++)
		std::cout << screen[i] << std::endl;
}

int		get_player_input ( int max_index )
{
	int		index;

	while (true)
	{
		std::cout << "> ";
		std::cin >> index;
		{
			if (std::cin.fail())
				std::cin.clear();
		}
		std::cin.ignore(1024, '\n');
		if (index > 0 && index <= max_index)
			break ;
	}
	return (index);
}

void	clear_dialogue ( void ) {
	std::cout << std::setw(80) << "" << std::endl << std::setw(80) << "" << "\r\033[1A";
}

void	print_dialogue( std::string dialogue1, std::string dialogue2 )
{
	clear_dialogue();
	for (size_t i = 0; i < dialogue1.length();)
	{
		char first_byte = dialogue1[i];
		if ((first_byte & 0x80) == 0x00)
			std::cout << dialogue1.substr(i++, 1);
		else {
			size_t len = 1;
			while ((dialogue1[i + len] & 0xC0) == 0x80)
				len++;
			std::cout << dialogue1.substr(i, len);
			i += len;
		}
		std::cout.flush();
		usleep(100000);
	}
	std::cout << std::endl;
	for (size_t i = 0; i < dialogue2.length();)
	{
		char first_byte = dialogue2[i];
		if ((first_byte & 0x80) == 0x00)
			std::cout << dialogue2.substr(i++, 1);
		else {
			size_t len = 1;
			while ((dialogue2[i + len] & 0xC0) == 0x80)
				len++;
			std::cout << dialogue2.substr(i, len);
			i += len;
		}
		std::cout.flush();
		usleep(70000);
	}
	std::cout << "\r\033[1A";
	usleep(1000000);
}
