#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);

	virtual void	execute(Bureaucrat const &executor) const;
};

#endif
