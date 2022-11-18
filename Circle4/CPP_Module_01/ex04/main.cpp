#include <string>
#include <iostream>
#include <fstream>

void	sed_for_loser(char *argv[]);
void	sed_for_winner(char *argv[]);

int main(int argc, char *argv[]) {
	std::string	command("");

	if (argc == 5 && std::string(argv[1]).compare("loser") == 0)
		sed_for_loser(argv);
	else if (argc == 4)
		sed_for_winner(argv);
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}

void	sed_for_loser(char *argv[]) {
	std::string	command = "";

	command.append("< ").append(argv[2]);
	command.append(" sed s/").append(argv[3]).append("/").append(argv[4]).append("/g ");
	command.append(">").append(argv[2]).append(".replace");

	std::cout << "Hahaha!! I'm the loser! LOL!!" << std::endl;
	system(command.c_str());
}
