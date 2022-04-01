#include "Intern.hpp"

const std::string	Intern::_FORM_NAME[3] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

Intern::Intern(void)
{
	std::cout<<"Called Intern(void)"<<std::endl;
}

Intern::Intern(const Intern &rhs)
{
	*this = rhs;
	std::cout<<"Called Intern(const Intern &rhs)"<<std::endl;
}

Intern::~Intern(void)
{
	std::cout<<"Called ~Intern(void)"<<std::endl;
}

Intern&	Intern::operator=(const Intern &rhs)
{
	return (*this);
}

Form*	Intern::makeForm(const std::string &form_name, const std::string &form_target)
{
	Form	*form = nullptr;
	int		idx = 0;

	for (; idx < 3; idx++)
	{
		if (Intern::_FORM_NAME[idx] == form_name)
			break ;
	}
	try
	{
		switch (idx)
		{
		case 0:
			form = new ShrubberyCreationForm(form_target);
			break ;
		case 1:
			form = new RobotomyRequestForm(form_target);
			break ;
		case 2:
			form = new PresidentialPardonForm(form_target);
			break ;
		default:
			throw (Intern::NoFormNameException());
		}
		std::cout<<"Intern creates "<<form->getName()<<", this target is "<<form->getTarget()<<std::endl;
	}
	catch(const Intern::NoFormNameException &e1)
	{
		std::cerr<<"Intern failed to make "<<form_name<<" because "<<e1.what()<<std::endl;
	}
	catch(const std::exception &e2)
	{
		std::cerr<<"Dynamic allocation failed: "<<e2.what()<<std::endl;
	}
	return (form);
}
