#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>

#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0m"

int	main(void)
{
	std::cout<<YELLOW<<"====== BASIC ======"<<DEFAULT<<std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout<<std::endl;
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	//[...]

	mstack.push(0);

	std::cout<<std::endl;
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout<<std::endl;
	std::cout<<YELLOW<<"====== MORE ======="<<DEFAULT<<std::endl;
	std::cout<<"----- STACK ------"<<std::endl;
	std::stack<int>::size_type	size = s.size();
	std::cout<<"stack<int> s - size: "<<size<<std::endl;
	std::cout<<"stack<int> s - empty: "<<s.empty()<<std::endl;
	std::cout<<"s - top: "<<s.top()<<std::endl;
	std::cout<<"s - top: "<<s.top()<<std::endl;

	std::cout<<std::endl;
	for (std::stack<int>::size_type i = 0; i < size; ++i)
	{
		std::cout<<"stack<int> s - top: "<<s.top()<<std::endl;
		s.pop();
	}
	std::cout<<std::endl;
	std::cout<<"stack<int> s - size: "<<size<<std::endl;
	std::cout<<"stack<int> s - empty: "<<s.empty()<<std::endl;
//	std::cout<<"s - top: "<<s.top()<<std::endl;			// Segmentation fault (core dumped) because stack is empty

	std::cout<<std::endl;
	std::cout<<"-- MUTANTSTACK ---"<<std::endl;
	MutantStack<char>	cmstack;

	for (char i = 'a'; i <= 'z'; i++)
		cmstack.push(i);
	for (MutantStack<char>::iterator itr = cmstack.begin(); itr != cmstack.end(); ++itr)
	{
		std::cout.width(2);
		std::cout<<*itr <<" ";
	}
	std::cout<<std::endl;
	for (char i = 'a'; i <= 'z'; i++)
	{
		std::cout.width(2);
		std::cout<<static_cast<int>(i) - 97<<" ";
	}
	std::cout<<std::endl;

	std::cout<<std::endl;
	char	tmp = 'o';

	MutantStack<char>::iterator	iter = std::find(cmstack.begin(), cmstack.end(), tmp);
	if (iter == cmstack.end())
	{
		std::cout<<"Not found: \'"<<tmp<<"\'"<<std::endl;
		return (0);
	}

	MutantStack<char>::const_iterator	const_iter = iter;

	std::cout<<"cmstack["<<std::distance(cmstack.begin(), iter)<<"]: "<<*const_iter<<std::endl;
	return (0);
}