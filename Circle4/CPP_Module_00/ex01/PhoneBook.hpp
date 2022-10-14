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
	bool	show_list(void);
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

bool	PhoneBook::show_list(void)
{
	if (this->size() == 0)
	{
		std::cout << "no contact here" << std::endl;
		return (false);
	}
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "\n";
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		this->contacts[i].display_info();
	}
	std::cout << std::fixed;
	return (true);
}

void	PhoneBook::search(int index)
{
	if (index < 1 || index > this->size())
		std::cout << "wrong index\n";
	else
		this->contacts[index - 1].display_all();
}

#endif
