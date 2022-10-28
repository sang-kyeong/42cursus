#include <string>
#include "StringEditor.hpp"

StringEditor::StringEditor( void )
{
	this->_str.clear();
}

StringEditor::~StringEditor ( void )
{

}

void	StringEditor::set_string(std::string str)
{
	this->_str = str;
}

std::string	StringEditor::get_string( void )
{
	return (this->_str);
}

void	StringEditor::replace(std::string from, std::string to)
{
	std::string	replaced;
	size_t		index;
	size_t		next_index;

	replaced.clear();
	index = 0;
	next_index = this->_str.find(from, index);
	while (next_index != _str.npos)
	{
		replaced.append(this->_str.substr(index, next_index - index));
		replaced.append(to);
		index = next_index + from.length();
		next_index = this->_str.find(from, index);
	}
	replaced.append(this->_str.substr(index));
	this->_str = replaced;
}
