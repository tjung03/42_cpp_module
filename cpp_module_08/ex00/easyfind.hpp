#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

class	NotFound : public std::exception
{
public:
	virtual const char* what(void) const throw()
	{
		return ("* Not Found *");
	}
};

template <typename T>
typename T::iterator	easyfind(T &container, int num)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), num);
	if (itr == container.end())
		throw (NotFound());
	return (itr);
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int num)
{
	typename T::const_iterator itr = std::find(container.begin(), container.end(), num);
	if (itr == container.end())
		throw (NotFound());
	return (itr);
}

template <typename T>
void	printContainer(T &con)
{
	//for (typename T::iterator itr = con.begin(); itr != con.end(); ++itr)
	//	std::cout<<*itr<<" ";
	for (const auto& elem : con)
		std::cout<<elem<<"  ";
}

template <typename T>
void	printEasyFind(T &con, int num)
{
	try {
		typename T::iterator begin = con.begin();
		typename T::iterator itr = easyfind(con, num);
		std::cout<<"T["<<std::distance(begin, itr)<<"]: "<<*itr<<std::endl;
	} catch (NotFound &e) {
		std::cerr<<e.what()<<std::endl;
	} catch (std::exception &e) {
		std::cerr<<"UNKNOWN"<<std::endl;
	}
}

#endif
