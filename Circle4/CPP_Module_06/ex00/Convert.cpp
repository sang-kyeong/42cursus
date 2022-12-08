# include <iostream>
#include "Convert.hpp"

Convert::t_type	Convert::recognize_type ( const std::string s )
{
	if (s.at(0) == '\'')
	{

	}
	else
	{
		if (s.)
	}
}

void	Convert::convert_char ( const std::string s )
{
	char	c = s.at(1);

	std::cout
		<< "char: " << c << std::endl
		<< "int: " << static_cast<int>(c) << std::endl
		<< "float: " << static_cast<float>(c) << std::endl
		<< "double: " << static_cast<double>(c) << std::endl;
}

void	Convert::convert_int ( const std::string s )
{
	int		i = std::stof(s);

	std::cout
		<< "char: " << i << std::endl
		<< "int: " << static_cast<int>(i) << std::endl
		<< "float: " << static_cast<float>(i) << std::endl
		<< "double: " << static_cast<double>(i) << std::endl;
}

void	Convert::convert_float ( const std::string s )
{
	float	f = std::stof(s);
}

void	Convert::convert_double ( const std::string s )
{
	double	d = std::stod(s);
}

void	Convert::convert_unknown ( const std::string s )
{

}
