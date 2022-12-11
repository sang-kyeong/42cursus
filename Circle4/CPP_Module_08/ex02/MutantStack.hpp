#ifndef __MUTANT_STACK_H__
# define __MUTANT_STACK_H__

# include <stack>

template < class T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
private:

protected:

public:
	typedef typename std::stack<T, C>::container_type::iterator	iterator;

	MutantStack ( void );
	MutantStack ( const MutantStack & other );
	~MutantStack ( void );

	MutantStack &	operator= ( const MutantStack & other );

	iterator	begin ( void );
	iterator	end ( void );
	iterator	rbegin ( void );
	iterator	rend ( void );

};

# include "MutantStack.tpp"

#endif//__MUTANT_STACK_H__
