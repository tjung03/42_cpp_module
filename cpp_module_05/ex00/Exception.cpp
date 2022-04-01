#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("* grade too high *");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("* grade too low *");
}
