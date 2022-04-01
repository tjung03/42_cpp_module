#include "Bureaucrat.hpp"

const int	Bureaucrat::HIGHEST_GRADE = 1;
const int	Bureaucrat::LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(Bureaucrat::LOWEST_GRADE)
{
	std::cout<<"Called Bureaucrat(void)"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name)
	: _name(name), _grade(Bureaucrat::LOWEST_GRADE)
{
	std::cout<<"Called Bureaucrat(const std::string &name)"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
	 : _name(name), _grade(grade)
{
	checkGradeException(this->getGrade());
	std::cout<<"Called Bureaucrat(const std::string &name, const int grade)"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
	: _name(rhs.getName()), _grade(rhs.getGrade())
{
	checkGradeException(this->getGrade());
	std::cout<<"Called Bureaucrat(const Bureaucrat &rhs)"<<std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout<<"Called ~Bureaucrat(void)"<<std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setGrade(rhs.getGrade());
	}
	checkGradeException(this->getGrade());
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(const int val)
{
	this->checkGradeException(this->getGrade() - val);
	this->setGrade(this->getGrade() - val);
}

void	Bureaucrat::decrementGrade(const int val)
{
	this->checkGradeException(this->getGrade() + val);
	this->setGrade(this->getGrade() + val);
}

void	Bureaucrat::setName(const std::string &name)
{
	const_cast<std::string&>(this->_name) = name;
}

void	Bureaucrat::setGrade(const int grade)
{
	this->_grade = grade;
}

void	Bureaucrat::checkGradeException(const int grade)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::signForm(Form &rhs)
{
	try
	{
		rhs.beSigned(*this);
		std::cout<<this->getName()<<" signed "<<rhs.getName()<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr<<this->getName()<<" couldn't sign "<<rhs.getName() \
		<<" because "<<e.what()<<std::endl;
	}
}

void	Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout<<this->getName()<<" executed "<<form.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<<this->getName()<<" couldn't execute "<<form.getName() \
		<<" because "<<e.what()<<std::endl;
	}

}
