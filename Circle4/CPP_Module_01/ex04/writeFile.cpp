#include <string>
#include <fstream>

int	write_file(std::string filename, std::string &content)
{
	std::ofstream	ofs;
	std::string		buffer;

	ofs.open(filename);
	if (ofs.fail())
		return (1);

	ofs << content;
	if (ofs.fail())
		return (1);
	else
		return (0);
}
