#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	std::string	command("");

	if (argc != 4)
		return (-1);

	command.append("< ").append(argv[1]);
	command.append(" sed s/").append(argv[2]).append("/").append(argv[3]).append("/g ");
	command.append(">").append(argv[1]).append(".replace");

	std::cout << "Haha!! I'm the loser! " << std::endl;
	std::cout << "Baaaaaam" << std::endl;
	return (system(command.c_str()));
}
