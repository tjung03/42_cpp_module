#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
	this->setName("PresidentialPardonForm");
	this->setReqSignGrade(25);
	this->setReqExecuteGrade(5);
	std::cout<<"Called PresidentialPardonForm(void)"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("President", 25, 5)
{
	this->setTarget(target);
	std::cout<<"Called PresidentialPardonForm(const std::string &type)"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
	: Form(rhs)
{
	this->setTarget(rhs.getTarget());
	std::cout<<"Called PresidentialPardonForm(const PresidentialPardonForm &rhs)"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout<<"Called ~PresidentialPardonForm(void)"<<std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getIsSigned()))
		throw (PresidentialPardonForm::NotSignedException());
	if (executor.getGrade() > this->getReqExecuteGrade())
		throw (PresidentialPardonForm::GradeTooLowException());

	std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}
