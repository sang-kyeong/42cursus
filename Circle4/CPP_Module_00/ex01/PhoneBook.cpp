#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_nb_contact = 0;
	for (int i = 0; i < 8; i++)
		_contacts[i] = Contact();
}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::add_contact(void)
{
	Contact		contact;
	std::string	input;

	while (true)
	{
		std::cout << "first name\t: ";
		std::getline(std::cin, input);
		if (input.length() > 0)
			break ;
	}
	contact.set_first_name(input);

	while (true)
	{
		std::cout << "last name\t: ";
		std::getline(std::cin, input);
		if (input.length() > 0)
			break ;
	}
	contact.set_last_name(input);

	while (true)
	{
		std::cout << "nickname\t: ";
		std::getline(std::cin, input);
		if (input.length() > 0)
			break ;
	}
	contact.set_nickname(input);

	while (true)
	{
		std::cout << "phone number\t: ";
		std::getline(std::cin, input);
		if (input.length() > 0)
			break ;
	}
	contact.set_phone_number(input);

	while (true)
	{
		std::cout << "darkest secret\t: ";
		std::getline(std::cin, input);
		if (input.length() > 0)
			break ;
	}
	contact.set_darkest_secret(input);

	this->add(contact);
	std::cout << std::endl << "New contact is added" << std::endl;
}

void	PhoneBook::search_contact(void) const
{
	int		index;

	if (!this->display_list())
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	std::cout << "index > ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "Wrong input" << std::endl;
	}
	else if (!this->display_info(index))
		std::cout << "Index out of range" << std::endl;
	std::cin.ignore(1024, '\n');
}

void	PhoneBook::add(Contact _contact)
{
	if (this->_nb_contact == 8)
		this->_contacts[7] = _contact;
	else
		this->_contacts[_nb_contact++] = _contact;
}

bool	PhoneBook::display_list(void) const
{
	if (this->_nb_contact == 0)
		return (false);

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
	for (int index = 0; index < _nb_contact; index++)
	{
		std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
		std::cout << "│" << std::setw(10) << index + 1 << "|";
		this->_contacts[index].display_name();
		std::cout << "│" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	return (true);
}

bool	PhoneBook::display_info(int index) const
{
	if (index < 1 || index > this->_nb_contact)
		return (false);
	this->_contacts[index - 1].display_all_info();
	return (true);
}
