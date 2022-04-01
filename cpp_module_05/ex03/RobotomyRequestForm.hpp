#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class	RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);

	virtual void	execute(Bureaucrat const &executor) const;

	class	FailedRobotomy : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

#endif
