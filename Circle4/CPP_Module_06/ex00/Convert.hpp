#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <string>

namespace Convert
{
	typedef enum e_type
	{
		char_type = 0,
		int_type,
		float_type,
		double_type,
		unknown_type,
	}	t_type;

	Convert::t_type	recognize_type ( const std::string literal );
	void	convert ( char c_value );
	void	convert ( int i_value );
	void	convert ( float f_value );
	void	convert ( double d_value );
	void	convert ( void );
}

#endif//__CONVERT_H__
