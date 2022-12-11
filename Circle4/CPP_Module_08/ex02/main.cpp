#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int	main ( void )
{
	{
		MutantStack<int> mstack;

		mstack.push(5);									// [5]
		mstack.push(17);								// [5, 17]

		std::cout << mstack.top() << std::endl;			// [5, 17]				17

		mstack.pop();									// [5]

		std::cout << mstack.size() << std::endl;		// [5]					1

		mstack.push(3);									// [5, 3]
		mstack.push(5);									// [5, 3, 5]
		mstack.push(737);								// [5, 3, 5, 737]
		//[...]
		mstack.push(0);									// [5, 3, 5, 737, 0]

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;				// [5, 3, 5, 737, 0]	5 3 5 737 0
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		MutantStack<int, std::vector<int> > mstack;

		mstack.push(5);									// [5]
		mstack.push(17);								// [5, 17]
		std::cout << mstack.top() << std::endl;			// [5, 17]				17
		mstack.pop();									// [5]
		std::cout << mstack.size() << std::endl;		// [5]					1
		mstack.push(3);									// [5, 3]
		mstack.push(5);									// [5, 3, 5]
		mstack.push(737);								// [5, 3, 5, 737]
		mstack.push(0);									// [5, 3, 5, 737, 0]
		MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
		MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;				// [5, 3, 5, 737, 0]	5 3 5 737 0
			++it;
		}
	}

	{
		MutantStack<int, std::list<int> > mstack;
		mstack.push(5);									// [5]
		mstack.push(17);								// [5, 17]
		std::cout << mstack.top() << std::endl;			// [5, 17]				17
		mstack.pop();									// [5]
		std::cout << mstack.size() << std::endl;		// [5]					1
		mstack.push(3);									// [5, 3]
		mstack.push(5);									// [5, 3, 5]
		mstack.push(737);								// [5, 3, 5, 737]
		mstack.push(0);									// [5, 3, 5, 737, 0]
		MutantStack<int, std::list<int> >::iterator it = mstack.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;				// [5, 3, 5, 737, 0]	5 3 5 737 0
			++it;
		}
	}
	return 0;
}
