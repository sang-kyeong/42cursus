#include <string.h>
#include <iostream>
#include "PhoneBook.hpp"

void	add_contact(PhoneBook *phone_book);
void	search_contact(PhoneBook *phone_book);

int main(void)
{
	const std::string	prompt = "> ";
	std::string			command;
	PhoneBook			phone_book;

	while (true)
	{
		std::cin.clear();
		std::cout << prompt;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phone_book.add_contact();
		else if (command.compare("SEARCH") == 0)
			phone_book.search_contact();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "usage : ADD, SEARCH, EXIT" << std::endl;
	}
	system("leaks phonebook | grep total");
	return (0);
}
