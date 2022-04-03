#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <exception>

class	InvalidMainArguException : public std::exception
{
public:
	virtual const char*	what(void) const throw();
};

#endif
