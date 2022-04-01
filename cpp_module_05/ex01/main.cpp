#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Bureaucrat	jun("junselee", 10);
	Bureaucrat	sun("sungclee", 30);
	Bureaucrat	hye("hyechoi", 150);
	std::cout<<std::endl;
	showBureaucrat(jun);
	showBureaucrat(sun);
	showBureaucrat(hye);

	std::cout<<std::endl;
	showTitle("Exception handling when creating an object");
	Form	resume1("resume1", 30, 1);
	Form	resume2("resume2", 100, 1);
	showForm(resume1);
	showForm(resume2);

	std::cout<<std::endl;
	try
	{
		Form	resume3("resume3", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	resume3("resume4", 150, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	resume3("resume5", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	resume3("resume6", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout<<std::endl;
	showTitle("Exception handling for comparison between Bureaucrat and Form");
	hye.signForm(resume2);
	showForm(resume2);
	jun.signForm(resume2);
	showForm(resume2);
	sun.signForm(resume1);
	showForm(resume1);

	std::cout<<std::endl;
	return (0);
}
