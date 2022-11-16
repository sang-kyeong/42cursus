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
		std::cout << "usage : ADD, SEARCH, EXIT" << std::endl;
		std::cout << prompt;
		std::cin >> command;
		std::cin.ignore(1024, '\n');
		if (command.compare("ADD") == 0 || command.compare("add") == 0)
			phone_book.add_contact();
		else if (command.compare("SEARCH") == 0 || command.compare("search") == 0)
			phone_book.search_contact();
		else if (command.compare("EXIT") == 0 || command.compare("exit") == 0)
			break ;
		else
			std::cout << "Wrong command" << std::endl;
	}
	return (0);
}
