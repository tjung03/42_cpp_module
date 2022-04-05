#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
private:
	static const std::string	_FORM_NAME[3];
	Form*	(Intern::*_automateFunc[3])(const std::string&);

public:
	Intern(void);
	Intern(const Intern &rhs);
	virtual ~Intern(void);

	Intern&	operator=(const Intern &rhs);

	Form*	makeForm(const std::string &form_name, const std::string &form_target);

	Form*	newShrubbey(const std::string &);
	Form*	newRobotomy(const std::string &);
	Form*	newPresident(const std::string &);

	class	NoFormNameException : public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};
};

#endif
