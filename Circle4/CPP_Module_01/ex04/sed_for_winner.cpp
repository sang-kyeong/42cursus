#include <string>
#include <iostream>
#include <fstream>

int		read_original(std::string file_name, std::string &content);
int		write_replace(std::string file_name, std::string &content, std::string from, std::string to);

void	sed_for_winner(char *argv[]) {
	std::string		content;

	content.clear();
	if (read_original(std::string(argv[1]), content) != 0)
		return ;
	if (write_replace(std::string(argv[1]).append(".replace"), content, std::string(argv[2]), std::string(argv[3])) != 0)
		return ;
}

int		read_original(std::string file_name, std::string &content) {
	std::ifstream	input_file_stream;
	std::string		buffer;

	input_file_stream.open(file_name);
	if (!input_file_stream.is_open())
	{
		std::cerr << "file open error" << file_name << std::endl;
		return (1);
	}
	while (std::getline(input_file_stream, buffer))
	{
		content.append(buffer);
		if (input_file_stream.eof())
			break;
		else
			content.append("\n");
	}
	if (input_file_stream.eof())
	{
		input_file_stream.close();
		return (0);
	}
	else
	{
		std::cerr << "file read error : " << file_name << std::endl;
		input_file_stream.close();
		return (1);
	}
}

int		write_replace(std::string file_name, std::string &content, std::string from, std::string to) {
	std::ofstream	output_file_stream;
	size_t	index = 0, next_word;

	output_file_stream.open(file_name);
	if (!output_file_stream.is_open())
	{
		std::cerr << "file open error : " << file_name << std::endl;
		return (1);
	}

// start
	next_word = content.find(from, index);
	while (next_word != content.npos)
	{
		output_file_stream << content.substr(index, next_word - index) << to;
		if (output_file_stream.fail())
		{
			std::cerr << "file write error : " << file_name << std::endl;
			output_file_stream.close();
			return (1);
		}
		index = next_word + std::string(from).length();
		next_word = content.find(from, index);
	}
	output_file_stream << content.substr(index);
	output_file_stream.close();
	return (0);
}
