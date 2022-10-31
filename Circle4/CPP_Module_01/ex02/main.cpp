#include <string>
#include <iostream>

int	main(void)
{
	std::string	stringORG("HI THIS IS MY BRAIN");

	std::string	*stringPTR = &stringORG;
	std::string &stringREF = stringORG;

	std::cout << "address of ORG : " << &stringORG << std::endl;
	std::cout << "address of PTR : " << stringPTR << std::endl;
	std::cout << "address of REF : " << &stringREF << std::endl << std::endl;

	std::cout << "value of ORG : " << stringORG << std::endl;
	std::cout << "value of PTR : " << *stringPTR << std::endl;
	std::cout << "value of REF : " << stringREF << std::endl << std::endl;

	std::cout << "done" << std::endl;
	return (0);
}
