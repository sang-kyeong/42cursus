#ifndef __HARL_H__
# define __HARL_H__

# include <string>

# define MSG_DEBUG		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define MSG_INFO		"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define MSG_WARNING	"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# define MSG_ERROR		"This is unacceptable! I want to speak to the manager now."
# define MSG_NORMAL		"What are you talk about! Say something I can understand!"

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
