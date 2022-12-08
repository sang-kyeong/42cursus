#include <iostream>
#include "Convert.hpp"
#include "Color.hpp"

int main ( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << RED << "convert get one parameter" << NORMAL << std::endl;
		return 1;
	}

	switch (Convert::recognize_type(argv[1]))
	{
	case Convert::Character :
		Convert::convert_char(argv[1]);
		break ;
	case Convert::Integer :
		Convert::convert_int(argv[1]);
		break ;
	case Convert::Float :
		Convert::convert_float(argv[1]);
		break ;
	case Convert::Double :
		Convert::convert_double(argv[1]);
		break ;
	default :
		Convert::convert_unknown(argv[1]);
		break ;
	}
	return 0;
}