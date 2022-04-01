#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("* grade too high *");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("* grade too low *");
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("* grade too high *");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("* grade too low *");
}
