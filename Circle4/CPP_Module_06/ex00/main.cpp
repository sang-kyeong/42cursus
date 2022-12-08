#include <iostream>
#include <iomanip>
#include "Convert.hpp"
#include "Color.hpp"

#include <iomanip>
int main ( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << RED << "convert get one parameter" << NORMAL << std::endl;
		return 1;
	}
	else if (std::string(argv[1]).length() == 0)
	{
		std::cout << RED << "empty string detected" << NORMAL << std::endl;
		return 1;
	}

	std::cout << std::setprecision(1) << std::fixed;
	switch (Convert::recognize_type(std::string(argv[1])))
	{
	case Convert::char_type :
		Convert::convert(argv[1][1]);
		break ;
	case Convert::int_type :
		Convert::convert(static_cast<int>(std::strtol(argv[1], NULL, 10)));
		break ;
	case Convert::float_type :
		Convert::convert(std::strtof(argv[1], NULL));
		break ;
	case Convert::double_type :
		Convert::convert(std::strtod(argv[1], NULL));
		break ;
	default :
		Convert::convert();
		break ;
	}
	return 0;
}
