#include "Bureaucrat.hpp"

# define YELLOW "\e[33m"
# define DEFAULT "\e[0m"

void	showTitle(const std::string &title)
{
	std::cout<<YELLOW;
	std::cout<<"-----<"<<title<<">------"<<std::endl;
	std::cout<<DEFAULT;
}

void	showValues(const Bureaucrat &obj)
{
	std::cout<<"-> "<<obj<<std::endl;
}

int	main(void)
{
	showTitle("Exception handling when creating an object");
	Bureaucrat jun("junselee", 1);
	showValues(jun);
	Bureaucrat sun("sungclee", 150);
	showValues(sun);
	Bureaucrat hye("hyechoi", 75);
	showValues(hye);
	try
	{
		Bureaucrat kyu("kyukim", 0);
		showValues(kyu);
	}
	catch(const std::exception &e)
	{
		std::cerr << "1. " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat kyu2(Bureaucrat("kyukim", 151));
		showValues(kyu2);
	}
	catch(const std::exception &e)
	{
		std::cerr << "2. " << e.what() << std::endl;
	}
	std::cout<<std::endl;
	showTitle("Exception handling for increasing or decreasing values");
	std::cout<<" [increment 30]"<<std::endl;
	showValues(sun);
	showValues(jun);
	sun.incrementGrade(30);
	try
	{
		jun.incrementGrade(30);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	showValues(sun);
	showValues(jun);
	std::cout<<" [decrement 50]"<<std::endl;
	showValues(sun);
	showValues(jun);
	jun.decrementGrade(50);
	try
	{
		sun.decrementGrade(50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	showValues(sun);
	showValues(jun);
	return (0);
}
