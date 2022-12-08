#include <iostream>
#include "Base.hpp"
#include "Color.hpp"

Base::~Base ( void )
{
	std::cout << BLACK << "[Base] destructor" << NORMAL << std::endl;
}
