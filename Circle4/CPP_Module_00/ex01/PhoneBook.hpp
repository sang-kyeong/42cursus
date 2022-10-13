#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	int			count;
	Contact		contacts[8];
public:
	PhoneBook(void);
	~PhoneBook(void);
	int		size(void);
	void	add(Contact _contact);
	void	show_list(void);
	void	search(int index);
};

PhoneBook::PhoneBook(void)
{
	count = 0;
	for (int i = 0; i < 8; i++)
		contacts[i] = Contact();
}

PhoneBook::~PhoneBook(void)
{
}

int		PhoneBook::size(void)
{
	return (this->count);
}

void	PhoneBook::add(Contact _contact)
{
	if (this->count == 8)
		this->contacts[7] = _contact;
	else
		this->contacts[count++] = _contact;
}

void	PhoneBook::show_list(void)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setfill(' ') << std::setprecision(10);
		std::cout << i + 1 << '|';
		this->contacts[i].display_short();
	}
	std::cout << std::fixed;
}

void	PhoneBook::search(int index)
{
	this->contacts[index - 1].display();
}

#endif
