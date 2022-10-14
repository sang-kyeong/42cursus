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
	system("leaks phonebook | grep total");
}

void	add_contact(PhoneBook *phonebook)
{
	Contact		contact;
	std::string	input[5];

	std::cout << "first name\t: ";
	std::cin >> input[0];
	std::cout << "last name\t: ";
	std::cin >> input[1];
	std::cout << "nickname\t: ";
	std::cin >> input[2];
	std::cout << "phone number\t: ";
	std::cin >> input[3];
	std::cout << "darkest secret\t: ";
	std::cin >> input[4];
	contact.set(input[0], input[1], input[2], input[3], input[4]);
	phonebook->add(contact);
}

void	search_contact(PhoneBook *phonebook)
{
	int		index;

	if (!phonebook->show_list())
		return ;
	std::cout << "search > ";
	std::cin >> index;
	phonebook->search(index);
}
