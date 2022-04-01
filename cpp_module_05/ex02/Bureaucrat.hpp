#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	static const int	HIGHEST_GRADE;
	static const int	LOWEST_GRADE;

	void	setName(const std::string &name);
	void	setGrade(const int grade);
	void	checkGradeException(const int grade);

public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name);
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat(const Bureaucrat &rhs);
	virtual ~Bureaucrat(void);

	Bureaucrat&	operator=(const Bureaucrat &rhs);

	std::string	getName(void) const;
	int			getGrade(void) const;

	void	incrementGrade(const int val);
	void	decrementGrade(const int val);

	void	signForm(Form &rhs);
	void	executeForm(const Form &form);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream &ostream_, const Bureaucrat &rhs);

#endif
