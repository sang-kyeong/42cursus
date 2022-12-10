#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Convert.hpp"
# include <math.h>

Convert::t_type	Convert::recognize_type ( const std::string literal )
{
	// char literal
	if (literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'')
		return Convert::char_type;

	// integer literal
	char	*str_end;
	long	l_value = std::strtol(literal.data(), &str_end, 10);
	if (*str_end == '\0' && l_value <= static_cast<long>(INT_MAX) && l_value >= static_cast<long>(INT_MIN))
		return Convert::int_type;

	// special literal
	if (literal == "nanf" || literal == "+nanf" || literal == "-nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
		return  Convert::float_type;
	if (literal == "nan" || literal == "+nan" || literal == "-nan" || literal == "inf" || literal == "+inff" || literal == "-inf")
		return  Convert::double_type;

	// long
	if (*str_end != '.' && *str_end != '+'  && *str_end != '-' )
		return Convert::unknown_type;

	// float, double literal
	std::strtod(literal.data(), &str_end);
	if (std::string(str_end) == "f")
		return Convert::float_type;
	else if (*str_end == '\0')
		return Convert::double_type;
	else
		return Convert::unknown_type;
}


void	Convert::convert ( char c_value )
{
	if (!isprint(static_cast<int>(c_value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c_value << "'" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c_value) << std::endl;
	std::cout << "float: " << static_cast<float>(c_value)  << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c_value) << std::endl;
}

void	Convert::convert ( int i_value )
{
	if (i_value > static_cast<int>(CHAR_MAX) || i_value < static_cast<int>(CHAR_MIN))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(i_value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i_value) << "'" << std::endl;

	std::cout << "int: " << i_value << std::endl;
	std::cout << "float: " << static_cast<float>(i_value)  << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i_value) << std::endl;
}

void	Convert::convert ( float f_value )
{
	if (fpclassify(f_value) == FP_NORMAL || fpclassify(f_value) == FP_ZERO)
	{
		int	i_value = static_cast<int>(f_value);
		if (i_value > static_cast<int>(CHAR_MAX) || i_value < static_cast<int>(CHAR_MIN))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(i_value))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i_value) << "'" << std::endl;

		std::cout << "int: " << i_value << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}

	std::cout << "float: " << f_value  << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f_value) << std::endl;
}

void	Convert::convert ( double d_value )
{
	if (fpclassify(static_cast<float>(d_value)) == FP_NORMAL || fpclassify(static_cast<float>(d_value)) == FP_ZERO)
	{
		int	i_value = static_cast<int>(static_cast<float>(d_value));
		if (i_value > static_cast<int>(CHAR_MAX) || i_value < static_cast<int>(CHAR_MIN))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(i_value))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i_value) << "'" << std::endl;

		std::cout << "int: " << i_value << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}

	std::cout << "float: " << static_cast<float>(d_value)  << "f" << std::endl;
	std::cout << "double: " << d_value << std::endl;
}

void	Convert::convert ( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
