#ifndef __CONTACT_H__
# define __CONTACT_H__

# include <string>
# include <iostream>
# include <iomanip>

class Contact {

public:

	Contact( void );
	~Contact( void );

	void	set_index(int index);
	void	set_first_name(std::string first_name);
	void	set_last_name(std::string last_name);
	void	set_nickname(std::string nickname);
	void	set_phone_number(std::string phone_number);
	void	set_darkest_secret(std::string darkest_secret);

	void	display_name(void) const;
	void	display_all_info(void) const;

private:

	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;

};

#endif /* __CONTACT_H__ */
