#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Color.hpp"

Base *	generate ( void );
void	identify ( Base * p );
void	identify ( Base & p );

int	main ( void )
{
	srand(time(NULL));
	Base *base;
	for (int i = 0; i < 5; i++)
	{
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
}

Base *	generate ( void )
{
	switch(rand() % 3)
	{
	case 0:
		std::cout << YELLOW << "A generated" << NORMAL << std::endl;
		return new A();
	case 1:
		std::cout << GREEN << "B generated" << NORMAL << std::endl;
		return new B();
	case 2:
		std::cout << MAGENTA << "C generated" << NORMAL << std::endl;
		return new C();
	default:
		std::cout << RED << "Base generated" << NORMAL << std::endl;
		return new Base();
	}
}

void	identify ( Base * p )
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << YELLOW << "It is A" << NORMAL << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << GREEN << "It is B" << NORMAL << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << MAGENTA << "It is C" << NORMAL << std::endl;
	else
		std::cout << RED << "What is this?!?! Is it just Base?" << NORMAL << std::endl;
}

void	identify ( Base & p )
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << YELLOW << "It is A" << NORMAL << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << GREEN << "It is B" << NORMAL << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << MAGENTA << "It is C" << NORMAL << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	std::cout << RED << "What is this?!?! Is it just Base?" << NORMAL << std::endl;
}