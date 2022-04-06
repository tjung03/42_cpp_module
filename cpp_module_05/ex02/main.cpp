#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0m"

void	showTitle(const std::string &title)
{
	std::cout<<YELLOW;
	std::cout<<"-----<"<<title<<">------"<<std::endl;
	std::cout<<DEFAULT;
}

void	showBureaucrat(const Bureaucrat &obj)
{
	std::cout<<"-> "<<obj<<std::endl;
}

void	showForm(const Form &obj)
{
	std::cout<<"-> "<<obj<<std::endl;
}

int	main(void)
{
	ShrubberyCreationForm	shrubbery("home");
	RobotomyRequestForm		robotomy("polarBear");
	PresidentialPardonForm	president("you");

	std::cout<<std::endl;
	showForm(shrubbery);
	showForm(robotomy);
	showForm(president);

	std::cout<<std::endl;
	Bureaucrat	person1("highest", 1);
	Bureaucrat	person2("lowest", 150);
	showBureaucrat(person1);
	showBureaucrat(person2);

	std::cout<<std::endl;
	showTitle("Exception handling for whether to sign or not");
	person1.executeForm(shrubbery);
	person1.executeForm(robotomy);
	person1.executeForm(president);
	std::cout<<std::endl;
	person2.executeForm(shrubbery);
	person2.executeForm(robotomy);
	person2.executeForm(president);

	std::cout<<std::endl;
	showTitle("Exception handling for whether to execute or not");
	std::cout<<"  !! highest'll sign it !!"<<std::endl;
	person1.signForm(shrubbery);
	person1.signForm(robotomy);
	person1.signForm(president);

	std::cout<<std::endl;
	showForm(shrubbery);
	showForm(robotomy);
	showForm(president);

	std::cout<<std::endl<<"  !! lowest'll execute it !!"<<std::endl;
	person2.executeForm(shrubbery);
	person2.executeForm(robotomy);
	person2.executeForm(president);

	std::cout<<std::endl<<"  !! highest'll execute it !!"<<std::endl;
	person1.executeForm(shrubbery);
	person1.executeForm(robotomy);
	person1.executeForm(president);

	std::cout<<std::endl;
	return (0);
}
