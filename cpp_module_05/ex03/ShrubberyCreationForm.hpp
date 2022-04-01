#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class	ShrubberyCreationForm : public Form
{
private:
	static const char	*_ASCII_TREE;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &rhs);

	virtual void	execute(Bureaucrat const &executor) const;

	class	FailedOpenFile : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

#endif
