#include "Exception.hpp"
#include "Converter.hpp"

const char*	InvalidMainArguException::what(void) const throw()
{
	return ("* Invalid arguments *");
}

const char*	Converter::InputException::what(void) const throw()
{
	return ("* Please enter \'char type\' or decimal number *");
}

const char*	Converter::NoDotFirstException::what(void) const throw()
{
	return ("* Please do not start with a dot *");
}
