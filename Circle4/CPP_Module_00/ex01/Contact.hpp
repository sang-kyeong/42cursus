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
	void	set_first_name(std::string _first_name);
	void	set(std::string _first_name, std::string _last_name, std::string _nickname, \
		std::string _phone_number, std::string _datkest_secret);
	void	display_short(void);
	void	display(void);
};

Contact::Contact(void)
{
	
}

Contact::~Contact(void)
{
	
}

void	Contact::set_first_name(std::string _first_name)
{
	this->first_name = _first_name;
}

void	Contact::set(std::string _first_name, std::string _last_name, std::string _nickname, \
	std::string _phone_number, std::string _datkest_secret)
{
	this->first_name = _first_name;
	this->last_name = _last_name;
	this->nickname = _nickname;
	this->phone_number = _phone_number;
	this->darkest_secret = _datkest_secret;
}

void	Contact::display_short(void)
{
	std::cout << std::setfill(' ') << std::setw(10) << std::setprecision(10);
	std::cout << this->first_name << '|';
	std::cout << std::setfill(' ') << std::setw(10) << std::setprecision(10);
	std::cout << this->last_name << '|';
	std::cout << std::setfill(' ') << std::setw(10) << std::setprecision(10);
	std::cout << this->nickname << '|' << std::endl;
}

void	Contact::display(void)
{
	std::cout << "first name     : " << this->first_name << std::endl;
	std::cout << "last name      : " << this->last_name << std::endl;
	std::cout << "nickname       : " << this->nickname << std::endl;
	std::cout << "phone number   : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}

#endif
