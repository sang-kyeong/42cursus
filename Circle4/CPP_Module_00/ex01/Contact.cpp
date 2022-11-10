#include <iostream>
#include <iomanip>

#include "Contact.hpp"

Contact::Contact( void )
{

}

Contact::~Contact( void )
{

}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void	Contact::display_name(void) const
{
	if (this->_first_name.size() > 10)
		std::cout << this->_first_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->_first_name << "|";

	if (this->_last_name.size() > 10)
		std::cout << this->_last_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->_last_name << "|";

	if (this->_nickname.size() > 10)
		std::cout << this->_nickname.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << this->_nickname;
}

void	Contact::display_all_info(void) const
{
	std::cout << "first name\t: " << this->_first_name << std::endl;
	std::cout << "last name\t: " << this->_last_name << std::endl;
	std::cout << "nickname\t: " << this->_nickname << std::endl;
	std::cout << "phone number\t: " << this->_phone_number << std::endl;
	std::cout << "darkest secret\t: " << this->_darkest_secret << std::endl;
}
