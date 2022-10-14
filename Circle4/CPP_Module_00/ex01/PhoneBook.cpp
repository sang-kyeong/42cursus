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

	std::cout << "first name\t: ";
	std::cin >> input;
	contact.set_first_name(input);
	std::cout << "last name\t: ";
	std::cin >> input;
	contact.set_last_name(input);
	std::cout << "nickname\t: ";
	std::cin >> input;
	contact.set_nickname(input);
	std::cout << "phone number\t: ";
	std::cin >> input;
	contact.set_phone_number(input);
	std::cout << "darkest secret\t: ";
	std::cin >> input;
	contact.set_darkest_secret(input);
	this->add(contact);
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
	if (!this->display_info(index))
		std::cout << "Wrong index" << std::endl;
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
	for (int index = 0; index < _nb_contact; index++)
	{
		std::cout << std::setw(10) << index + 1 << "|";
		this->_contacts[index].display_name();
	}
	return (true);
}

bool	PhoneBook::display_info(int index) const
{
	if (index < 1 || index > this->_nb_contact)
		return (false);
	this->_contacts[index - 1].display_all_info();
	return (true);
}
