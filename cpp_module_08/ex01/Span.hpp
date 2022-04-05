#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class	Span
{
private:
	unsigned int		_N;
	std::vector<int>	_vec;

	Span(void);

public:
	Span(unsigned int N);
	Span(const Span &rhs);
	virtual ~Span(void);

	Span&	operator=(const Span &rhs);

	void	addNumber(const int num);
	void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void	addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	unsigned int			getN(void) const;
	const std::vector<int>&	getVector(void) const;
	std::vector<int>&		getVector(void);

	class	FullSpanException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class	NotFoundSpanException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	const int&	operator[](unsigned int idx) const
	{
		if (idx >= this->_N || idx < 0)
			throw (std::exception());
		return (this->_vec[idx]);
	}

	int&	operator[](unsigned int idx)
	{
		if (idx >= this->_N || idx < 0)
			throw (std::exception());
		return (this->_vec[idx]);
	}
};

#endif
