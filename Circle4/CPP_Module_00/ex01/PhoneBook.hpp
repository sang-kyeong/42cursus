#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "Contact.hpp"

class PhoneBook
{

public:

	PhoneBook( void );
	~PhoneBook( void );

	void	add_contact( void );
	void	search_contact( void ) const;

private:

	int				_nb_contact;
	int				_next_index;
	Contact			_contacts[8];

	void	add(Contact _contact);
	bool	display_list(void) const;
	bool	display_info(int index) const;

};

#endif /* __PHONEBOOK_H__ */
