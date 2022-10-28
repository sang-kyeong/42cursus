#include <string>
#include <iostream>
#include "StringEditor.hpp"

int	read_file(std::string filename, std::string &content);
int	write_file(std::string filename, std::string &content);

int main(int argc, char *argv[])
{
	std::string		content;
	StringEditor	editor;

	if (argc != 4)
		return (127);

	if (read_file(std::string(argv[1]), content) == 1)
		return (1);
	std::cout << "read : " << content << std::endl;

	editor.set_string(content);
	editor.replace(std::string(argv[2]), std::string(argv[3]));
	content = editor.get_string();

	std::cout << "replaced : " << content << std::endl;
	if (write_file(std::string(argv[1]).append(".replace"), content) == 1)
		return (1);

	return (0);
}
