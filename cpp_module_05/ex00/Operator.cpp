#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream &ostream_, const Bureaucrat &rhs)
{
	ostream_ << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (ostream_);
}
