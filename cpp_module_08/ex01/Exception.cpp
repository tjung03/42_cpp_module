#include "Span.hpp"

const char* Span::FullSpanException::what(void) const throw()
{
	return ("* Span is Full *");
}

const char* Span::NotFoundSpanException::what(void) const throw()
{
	return ("* Not Found Span *");
}
