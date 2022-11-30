#ifndef __HARL_H__
# define __HARL_H__

# include <string>

# define MESSAGE_DEBUG		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!"
# define MESSAGE_INFO		"I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!"
# define MESSAGE_WARNING	"I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month."
# define MESSAGE_ERROR		"This is unacceptable, I want to speak to the manager now."
# define MESSAGE_NORMAL		"[ Probably complaining about insignificant problems ]"

class Harl
{
private:

	void	debug ( void );
	void	info ( void );
	void	warning ( void );
	void	error ( void );
	void	normal ( void );

public:

	Harl ( void );
	~Harl ( void );

	void	complain( std::string level );

};

#endif //__HARL_H__
