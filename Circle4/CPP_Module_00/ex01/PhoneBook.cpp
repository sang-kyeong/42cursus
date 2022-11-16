#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_nb_contact = 0;
	_next_index = 0;
	for (int i = 0; i < 8; i++)
		_contacts[i] = Contact();
	std:: cout << "Hello! Your phonebook is ready! ᕕ( ᐛ )ᕗ" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Goodbye ᕙ(`▽´)ᕗ" << std::endl;
}

std::string get_input(std::string field_name)
{
	std::string input;

	while (true)
	{
		std::cout << field_name << "\t: ";
		std::getline(std::cin, input);
		if (input.find("\t") != input.npos)
			std::cout << "Sorry, tab character isn't allowed" << std::endl;
		else if (input.length() > 0)
			break ;
	}
	return (input);
}

void	PhoneBook::add_contact(void)
{
	Contact		contact;

	contact.set_first_name(get_input("first name"));
	contact.set_last_name(get_input("last name"));
	contact.set_nickname(get_input("nickname"));
	contact.set_phone_number(get_input("phone number"));
	contact.set_darkest_secret(get_input("darkest secret"));

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

	while (true)
	{
		std::cout << "index > ";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Wrong input" << std::endl;
		}
		else if (!this->display_info(index))
			std::cout << "Index out of range" << std::endl;
		else
			break ;
		std::cin.ignore(1024, '\n');
	}
	std::cin.ignore(1024, '\n');
}

void	PhoneBook::add(Contact _contact)
{
	this->_contacts[_next_index % 8] = _contact;
	this->_next_index++;
	if (this->_nb_contact < 8)
		this->_nb_contact++;
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
