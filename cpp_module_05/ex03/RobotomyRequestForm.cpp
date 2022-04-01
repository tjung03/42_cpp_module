#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
	this->setName("RobotomyRequestForm");
	this->setReqSignGrade(72);
	this->setReqExecuteGrade(45);
	std::cout<<"Called RobotomyRequestForm(void)"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("Robotomy", 72, 45)
{
	this->setTarget(target);
	std::cout<<"Called RobotomyRequestForm(const std::string &type)"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
	: Form(rhs)
{
	this->setTarget(rhs.getTarget());
	std::cout<<"Called RobotomyRequestForm(const RobotomyRequestForm &rhs)"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout<<"Called ~RobotomyRequestForm(void)"<<std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getIsSigned()))
		throw (RobotomyRequestForm::NotSignedException());
	if (executor.getGrade() > this->getReqExecuteGrade())
		throw (RobotomyRequestForm::GradeTooLowException());

	std::cout<<"grrrr!! grrrr!! grrrrrrrrrr!!!"<<std::endl;

	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2)
		throw (RobotomyRequestForm::FailedRobotomy());
	std::cout<<this->getTarget()<<" has been robotomized successfully"<<std::endl;
}
