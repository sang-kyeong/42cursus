#include <string>
#include <iostream>
#include <fstream>

int		read_file(std::string file_name, std::string &content);
void	ft_replace(std::string &replaced, std::string &original, std::string form, std::string to);
int		write_file(std::string file_name, std::string &content);

void	sed_for_winner(char *argv[])
{
	std::string		content;
	std::string		content_r;

	if (read_file(std::string(argv[1]), content))
		return ;
	ft_replace(content_r, content, std::string(argv[2]), std::string(argv[3]));
	if (write_file(std::string(argv[1]).append(".replace"), content_r))
		return ;
}

int		read_file(std::string file_name, std::string &content)
{
	std::ifstream	input_file_stream;
	std::string		buffer;

	content.clear();
	input_file_stream.open(file_name);
	if (!input_file_stream.is_open())
	{
		std::cout << "input file open error" << std::endl;
		return (1);
	}
	while (std::getline(input_file_stream, buffer))
	{
		content.append(buffer);
		if (input_file_stream.eof())
			break ;
		else
			content.append("\n");
	}
	// if (input_file_stream.fail())
	// {
	// 	std::cout << "file read error" << std::endl;
	// 	input_file_stream.close();
	// 	return (1);
	// }
	input_file_stream.close();
	return (0);
}

void	ft_replace(std::string &replaced, std::string &original, std::string form, std::string to)
{
	size_t	index = 0, next_word = 0;
	next_word = original.find(form, index);
	while (next_word != original.npos)
	{
		replaced.append(original.substr(index, next_word - index)).append(to);
		index = next_word + std::string(form).length();
		next_word = original.find(form, index);
	}
	replaced.append(original.substr(index));
}

int		write_file(std::string file_name, std::string &content)
{
	std::ofstream	output_file_stream;

	output_file_stream.open(std::string(file_name).append(".replace"));
	if (!output_file_stream.is_open())
	{
		std::cout << "output file open error" << std::endl;
		return (1);
	}
	output_file_stream << content;
	if (output_file_stream.fail())
	{
		std::cout << "file write error" << std::endl;
		output_file_stream.close();
		return (1);
	}
	output_file_stream.close();
	return (0);
}
