#include "Form.hpp"

const int	Form::HIGHEST_GRADE = 1;
const int	Form::LOWEST_GRADE = 150;

Form::Form(void)
	: _name("Form"), _is_signed(false), _required_signature_grade(Form::LOWEST_GRADE), _required_execution_grade(Form::LOWEST_GRADE)
{
	std::cout<<"Called Form(void)"<<std::endl;
}

Form::Form(const std::string &name, const int req_sign_grade, const int req_execute_grade)
	: _name(name), _is_signed(false), _required_signature_grade(req_sign_grade), _required_execution_grade(req_execute_grade)
{
	checkGradeException(this->getReqSignGrade());
	checkGradeException(this->getReqExecuteGrade());
	std::cout<<"Called Form(const std::string &name, const int req_sign_grade, const int req_execute_grade)"<<std::endl;
}

Form::Form(const Form &rhs)
	: _name(rhs.getName()), _required_signature_grade(rhs.getReqSignGrade()), _required_execution_grade(rhs.getReqExecuteGrade())
{
	checkGradeException(this->getReqSignGrade());
	checkGradeException(this->getReqExecuteGrade());
	std::cout<<"Called Form(const Form &rhs)"<<std::endl;
}

Form::~Form(void)
{
	std::cout<<"Called ~Form(void)"<<std::endl;
}

Form&	Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setIsSigned(rhs.getIsSigned());
		this->setReqSignGrade(rhs.getReqSignGrade());
		this->setReqExecuteGrade(rhs.getReqExecuteGrade());
	}
	checkGradeException(this->getReqSignGrade());
	checkGradeException(this->getReqExecuteGrade());
	return (*this);
}

void	Form::setName(const std::string &name)
{
	const_cast<std::string&>(this->_name) = name;
}

void	Form::setIsSigned(bool signed_)
{
	this->_is_signed = signed_;
}

void	Form::setReqSignGrade(const int grade)
{
	const_cast<int&>(this->_required_signature_grade) = grade;
}

void	Form::setReqExecuteGrade(const int grade)
{
	const_cast<int&>(this->_required_execution_grade) = grade;
}

void	Form::checkGradeException(const int grade)
{
	if (grade < Form::HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	if (grade > Form::LOWEST_GRADE)
		throw (Form::GradeTooLowException());
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int	Form::getReqSignGrade(void) const
{
	return (this->_required_signature_grade);
}

int	Form::getReqExecuteGrade(void) const
{
	return (this->_required_execution_grade);
}

void	Form::beSigned(const Bureaucrat &rhs)
{
	if (rhs.getGrade() > this->getReqSignGrade())
		throw (Form::GradeTooLowException());
	this->setIsSigned(true);
}
