#include <string>
#include <iostream>
#include "Harl.hpp"

Harl::Harl ( void ) {   }

Harl::~Harl ( void ) {   }

void	Harl::complain( std::string level ) {
	void (Harl::*func)(void) = NULL;

	int mask = \
		((level.compare("DEBUG") == 0)   * 1) + \
		((level.compare("INFO") == 0)    * 2) + \
		((level.compare("WARNING") == 0) * 3) + \
		((level.compare("ERROR") == 0)   * 4);

	switch(mask)
	{
		case 1 :
			func = &Harl::debug;
			break ;
		case 2 :
			func = &Harl::info;
			break ;
		case 3 :
			func = &Harl::warning;
			break ;
		case 4 :
			func = &Harl::error;
			break ;
		default :
			func = &Harl::normal;
	}

	(this->*func)();
}

void	Harl::filter( std::string level ) {
	int mask = \
		((level.compare("DEBUG") == 0)   * 1) + \
		((level.compare("INFO") == 0)    * 2) + \
		((level.compare("WARNING") == 0) * 3) + \
		((level.compare("ERROR") == 0)   * 4);

	switch(mask)
	{
		case 1 :
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
		case 2 :
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
		case 3 :
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
			std::cout << std::endl;
		case 4 :
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break ;
		default :
			this->normal();
	}
}

void	Harl::debug ( void )	{ std::cout << MESSAGE_DEBUG	<< std::endl; }
void	Harl::info ( void )		{ std::cout << MESSAGE_INFO		<< std::endl; }
void	Harl::warning ( void )	{ std::cout << MESSAGE_WARNING	<< std::endl; }
void	Harl::error ( void )	{ std::cout << MESSAGE_ERROR	<< std::endl; }
void	Harl::normal (void )	{ std::cout << MESSAGE_NORMAL	<< std::endl; }
