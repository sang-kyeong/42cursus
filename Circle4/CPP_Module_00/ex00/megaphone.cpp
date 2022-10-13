#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string	s;
		for (int i = 1; i < argc; i++)
			s.append(argv[i]);
		for (unsigned long i = 0; i < s.size(); i++)
			s[i] = std::toupper(s[i]);
		std::cout << s << std::endl;
	}
	return (0);
}
