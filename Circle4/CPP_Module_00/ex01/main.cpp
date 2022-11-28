#include <string.h>
#include <iostream>
#include "PhoneBook.hpp"

void	add_contact(PhoneBook *phone_book);
void	search_contact(PhoneBook *phone_book);

int main(void) {
	const std::string	prompt = "> ";
	std::string			command;
	PhoneBook			phone_book;

	while (true)
	{
		std::cout << "usage : ADD, SEARCH, EXIT" << std::endl;
		std::cout << prompt;
		std::cin >> command;
		if (std::cin.eof())
			exit(1);
		std::cin.ignore(1024, '\n');
		if (command.compare("ADD") == 0)
			phone_book.add_contact();
		else if (command.compare("SEARCH") == 0)
			phone_book.search_contact();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Wrong command" << std::endl;
	}
	return (0);
}
