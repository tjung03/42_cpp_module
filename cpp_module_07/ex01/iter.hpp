#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void	iter(T *addr, int len, void (*func)(T&))
{
	if (addr == NULL || func == NULL)
		return ;
	for (int i = 0; i < len; i++)
		func(addr[i]);
}

template <typename T>
void	iter(const T *addr, int len, void (*func)(const T&))
{
	if (addr == NULL || func == NULL)
		return ;
	for (int i = 0; i < len; i++)
		func(addr[i]);
}

// iter 테스트 함수
template <typename T>
void	printArrElements(T &t)
{
	std::cout<<t<<" ";
}

template <typename T>
void	printPtrArrElements(T &t)
{
	std::cout<<*t<<" ";
}

template <typename T>
void	addStrOfArrElements(T &t)
{
	t = "add_" + t;
}

template <typename T>
void	addNumOfArrElements(T &t)
{
	++t;
}

template <typename T>
void	subNumofArrElements(T &t)
{
	--t;
}

#endif
