#ifndef __STRING_EDITOR_H__
# define __STRING_EDITOR_H__

# include <string>

class StringEditor
{
private:

	std::string	_str;

public:

	StringEditor( void );
	~StringEditor ( void );

	void	set_string(std::string str);
	std::string	get_string( void );

	void	replace(std::string from, std::string to);

};

#endif //__STRING_EDITOR_H__
