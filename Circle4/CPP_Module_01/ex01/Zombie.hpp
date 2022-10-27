

#include <string>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie ( void );
	Zombie (std::string name);
	~Zombie ( void );

	void	set_name(std::string);
	void	anounce ( void );
};
