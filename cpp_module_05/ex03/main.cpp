#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

# define YELLOW "\e[33m"
# define DEFAULT "\e[0m"

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
	Intern	intern;

	std::cout<<std::endl;
	showTitle("Interns try to make form");
	Form	*shru = intern.makeForm("ShrubberyCreationForm", "home");
	std::cout<<std::endl;
	Form	*robo = intern.makeForm("RobotomyRequestForm", "polarBear");
	std::cout<<std::endl;
	Form	*prsi = intern.makeForm("PresidentialPardonForm", "you");

	std::cout<<std::endl;
	showForm(*shru);
	showForm(*robo);
	showForm(*prsi);

	std::cout<<std::endl;
	showTitle("Interns failed to make form");
	try
	{
		Form	*test_fail = intern.makeForm("Form", "what");

		if (test_fail == nullptr)
			throw (std::string("nullptr"));
	}
	catch (std::string &expt)
	{
		std::cerr<<"Failed makeForm(): test_fail is "<<expt<<std::endl;
	}

	std::cout<<std::endl;
	delete prsi; delete robo; delete shru;
	return (0);
}
