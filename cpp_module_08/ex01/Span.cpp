#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(void) : _N(0) { }

Span::Span(unsigned int N) : _N(N) { }

Span::Span(const Span &rhs)
	: _N(rhs.getN()), _vec(rhs.getVector())
{ }

Span::~Span(void) { }

Span&	Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs.getN();
		this->_vec.clear();//
		std::vector<int>().swap(this->_vec);//
		this->_vec = rhs.getVector();
	}
	return (*this);
}

void	Span::addNumber(const int num)
{
	if (this->_vec.size() == this->_N)
		throw (Span::FullSpanException());
	this->_vec.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator itr = begin; itr != end; itr++)
		addNumber(*itr);
}

void	Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	for (std::vector<int>::const_iterator itr = begin; itr != end; ++itr)
		addNumber(*itr);
}

int	Span::shortestSpan(void) const
{
	if (this->_vec.size() <= 1)
		throw (Span::NotFoundSpanException());
	std::vector<int>	cpy = this->getVector();
	int	min_span = std::numeric_limits<int>::max();

	std::sort(cpy.begin(), cpy.end());
	int	before = *cpy.begin();
	for (std::vector<int>::iterator itr = cpy.begin() + 1; itr != cpy.end(); ++itr)
	{
		min_span = std::min(min_span, *itr - before);
		before = *itr;
	}
	return (min_span);
}

int	Span::longestSpan(void) const
{
	if (this->_vec.size() <= 1)
		throw (Span::NotFoundSpanException());
	std::vector<int>	tmp = this->getVector();

	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

unsigned int	Span::getN(void) const
{
	return (this->_N);
}

const std::vector<int>&	Span::getVector(void) const
{
	return (this->_vec);
}

std::vector<int>&	Span::getVector(void)
{
	return (this->_vec);
}
