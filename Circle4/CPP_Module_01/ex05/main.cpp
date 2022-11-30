#include <string>
#include <iostream>
#include "Harl.hpp"

int	main(void) {
	Harl		my_harl;
	std::string	input;

	std::cout << "[DEBUG]" << std::endl;
	my_harl.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << "[INFO]" << std::endl;
	my_harl.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "[WARNING]" << std::endl;
	my_harl.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "[ERROR]" << std::endl;
	my_harl.complain("ERROR");
	std::cout << std::endl;
	
	std::cout << "[DEBUGA]" << std::endl;
	my_harl.complain("DEBUGA");
	std::cout << std::endl;
	
	std::cout << "[DEBUG ]" << std::endl;
	my_harl.complain("DEBUG ");
	std::cout << std::endl;
	
	std::cout << "[DEFAULT]" << std::endl;
	my_harl.complain("DEFAULT");
	std::cout << std::endl;

	return (0);
}
