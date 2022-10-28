#include <string>
#include <fstream>
#include <iostream>

int	read_file(std::string filename, std::string &content)
{
	std::ifstream	ifs;
	std::string		buffer;

	ifs.open(filename);
	if (ifs.fail())
		return (1);
	
	content.clear();
	while (ifs.fail() == false && ifs.eof() == false)
	{
		std::getline(ifs, buffer);
		content.append(buffer).append("\n");
	}
	if (ifs.fail())
		return (1);
	else
		return (0);
}
