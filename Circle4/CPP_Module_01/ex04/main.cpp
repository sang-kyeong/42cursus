#include <string>
#include <iostream>
#include <fstream>

void	ft_sed(char *argv[]);
void	read_file(std::string file_name, std::string &content);
void	write_replace(std::string file_name, std::string &content, std::string from, std::string to);

int main(int argc, char *argv[])
{
	if (argc != 4)
		std::cout << "unterminated substitute in regular expression" << std::endl;
	else if (std::string(argv[2]).empty())
		std::cout << "first RE may not be empty" << std::endl;
	else
	{
		std::string		outfile(std::string(argv[1]) + ".replace");
		std::string		content;

		read_file(argv[1], content);
		write_replace(outfile, content, argv[2], argv[3]);
	}
	return (0);
}

void	read_file(std::string file_name, std::string &content)
{
	std::ifstream	input_file_stream;
	std::string		buffer;

	input_file_stream.open(file_name);
	if (!input_file_stream.is_open())
		exit (1);
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
		return ;
	}
	else
	{
		std::cerr << "file read error : " << file_name << std::endl;
		input_file_stream.close();
		exit (1);
	}
}

void	write_replace(std::string file_name, std::string &content, std::string from, std::string to)
{
	std::ofstream	output_file_stream;
	size_t			index = 0, next_word;
	size_t			form_length = from.length();

	output_file_stream.open(file_name);
	if (!output_file_stream.is_open())
		exit (1);
// start
	next_word = content.find(from, index);
	while (next_word != std::string::npos)
	{
		output_file_stream << content.substr(index, next_word - index) << to;
		if (output_file_stream.fail())
			exit (1);
		index = next_word + form_length;
		next_word = content.find(from, index);
	}
	output_file_stream << content.substr(index);
	output_file_stream.close();
	return ;
}
