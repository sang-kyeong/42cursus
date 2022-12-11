#ifndef __SPAN_H__
# define __SPAN_H__

# include <vector>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_vector;

protected:

public:
	Span ( void );
	Span ( unsigned int N );
	Span ( const Span & other );
	~Span ( void );
	
	Span &	operator= (const Span & other );

	void			addNumber ( int number );
	void			addNumbers ( std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int	shortestSpan ( void );
	unsigned int	longestSpan ( void );

};

#endif//__SPAN_H__
