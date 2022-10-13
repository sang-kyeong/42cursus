#include <string.h>
#include <iostream>
#include "PhoneBook.hpp"

void	add_contact(PhoneBook *phonebook);
void	search_contact(PhoneBook *phonebook);

int main(void)
{
	const std::string	prompt = "> ";
	std::string			command;
	PhoneBook			phonebook;

	while (true)
	{
		std::cout << prompt;
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			add_contact(&phonebook);
		}
		else if (command.compare("SEARCH") == 0)
		{
			search_contact(&phonebook);
		}
		else if (command.compare("EXIT") == 0)
			break ;
		std::cout.flush();
	}
	system("leaks phonebook");
}

void	add_contact(PhoneBook *phonebook)
{
	Contact		contact;
	std::string	input;

	while (true)
	{
		std::cout << "first name     : ";
		std::cin >> input;
		if (!input.empty())
		{
			contact.set_first_name(input);
			break ;
		}
		std::cout << "empty input" << std::endl;
	}
	phonebook->add(contact);
	// std::cout << "last name      : " << this->last_name << std::endl;
	// std::cout << "nickname       : " << this->nickname << std::endl;
	// std::cout << "phone number   : " << this->phone_number << std::endl;
	// std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}

void	search_contact(PhoneBook *phonebook)
{
	if (phonebook->size() == 0)
	{
		std::cout << "no contact here" << std::endl;
		return ;
	}
	phonebook->show_list();
}
