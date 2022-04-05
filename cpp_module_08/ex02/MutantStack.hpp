#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::iterator		iterator;

	MutantStack(void) : std::stack<T>() { }
	MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) { }
	virtual ~MutantStack(void) { }

	MutantStack&	operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return (*this);
	}

	const_iterator	begin(void) const { return (this->c.begin()); }
	const_iterator	end(void) const { return (this->c.end()); }
	iterator		begin(void) { return (this->c.begin()); }
	iterator		end(void) { return (this->c.end()); }
};

#endif
