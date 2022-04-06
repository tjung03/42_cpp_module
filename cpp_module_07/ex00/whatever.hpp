#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>
# include <cstring>

// swap
template <typename T>
void	swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

// min
template <typename T>
T&	min(T &a, T &b)
{
	return ((a < b) ? a : b);
}

// min const
template <typename T>
const T&	min(const T &a, const T &b)
{
	return ((a < b) ? a : b);
}

// max
template <typename T>
T&	max(T &a, T &b)
{
	return ((a > b) ? a : b);
}

// max const
template <typename T>
const T&	max(const T &a, const T &b)
{
	return ((a > b) ? a : b);
}

#endif
