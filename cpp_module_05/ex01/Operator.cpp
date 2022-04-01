#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream&	operator<<(std::ostream &ostream_, const Bureaucrat &rhs)
{
	ostream_ << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (ostream_);
}

std::ostream&	operator<<(std::ostream &ostream_, const Form &rhs)
{
	std::string	is_signed = "false";

	if (rhs.getIsSigned() == true)
		is_signed = "true";
	ostream_	<< rhs.getName() << ", Form is signed(" << is_signed << "), " \
				<< rhs.getName() << "'s Required Signature Grade is " << rhs.getReqSignGrade() << " and " \
				<< rhs.getName() << "'s Required Execution Graade is " << rhs.getReqExecuteGrade();
	return (ostream_);
}
