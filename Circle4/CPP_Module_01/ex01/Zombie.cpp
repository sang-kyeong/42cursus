#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie( void ) { std::cout << "A unknown zombie is created." << std::endl; }
Zombie::Zombie(std::string name) : _name(name) { std::cout << "A zombie is created. His name is " << this->_name << std::endl; }

Zombie::~Zombie ( void ) { std::cout << this->_name << " is destryed" << std::endl; }

void	Zombie::set_name(std::string name) {
	this->_name = name;
	std::cout << "My name is " << this->_name << std::endl; 
}

void	Zombie::anounce ( void ) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
