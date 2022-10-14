#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact(void);
	~Contact();
	void	set(std::string _first_name, \
		std::string _last_name, std::string _nickname, \
		std::string _phone_number, std::string _datkest_secret);
	void	display_info(void);
	void	display_all(void);
};

Contact::Contact(void)
{
	
}

Contact::~Contact(void)
{
	
}

void	Contact::set(std::string _first_name, \
	std::string _last_name, std::string _nickname, \
	std::string _phone_number, std::string _darkest_secret)
{
	this->first_name = _first_name;
	this->last_name = _last_name;
	this->nickname = _nickname;
	this->phone_number = _phone_number;
	this->darkest_secret = _darkest_secret;
}

void	Contact::display_info(void)
{
	if (this->first_name.size() > 10)
		std::cout << this->first_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->first_name << "|";

	if (this->last_name.size() > 10)
		std::cout << this->last_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->last_name << "|";

	if (this->nickname.size() > 10)
		std::cout << this->nickname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->nickname << "\n";
}

void	Contact::display_all(void)
{
	std::cout << "first name     : " << this->first_name << std::endl;
	std::cout << "last name      : " << this->last_name << std::endl;
	std::cout << "nickname       : " << this->nickname << std::endl;
	std::cout << "phone number   : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}

#endif
