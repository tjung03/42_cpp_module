#ifndef	FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_required_signature_grade;
	const int			_required_execution_grade;

	static const int	HIGHEST_GRADE;
	static const int	LOWEST_GRADE;

	void	setName(const std::string &name);
	void	setIsSigned(bool signed_);
	void	setReqSignGrade(const int grade);
	void	setReqExecuteGrade(const int grade);
	void	checkGradeException(const int grade);

public:
	Form(void);
	Form(const std::string &name, const int req_sign_grade, const int req_execute_grade);
	Form(const Form &rhs);
	~Form(void);

	Form&	operator=(const Form &rhs);

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getReqSignGrade(void) const;
	int			getReqExecuteGrade(void) const;

	void	beSigned(const Bureaucrat &rhs);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream &ostream_, const Form &rhs);

#endif
