#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <string>

namespace Convert
{
	typedef enum e_type
	{
		Character = 0,
		Integer,
		Float,
		Double,
		Unknown,
	}	t_type;

	t_type	recognize_type ( const std::string s );
	void	convert_char ( const std::string s );
	void	convert_int ( const std::string s );
	void	convert_float ( const std::string s );
	void	convert_double ( const std::string s );
	void	convert_unknown ( const std::string s );
}

#endif//__CONVERT_H__
