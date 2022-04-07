#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0m"

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout<<YELLOW<<"----- GENERATE ------"<<DEFAULT<<std::endl;
	Base	*base1 = generate();
	Base	*base2 = generate();
	Base	*base3 = generate();

	std::cout<<std::endl;
	std::cout<<YELLOW<<"----- PTR IDENTIFY ------"<<DEFAULT<<std::endl;
	std::cout<<"base1: ";
	identify(base1);
	std::cout<<"base2: ";
	identify(base2);
	std::cout<<"base3: ";
	identify(base3);

	std::cout<<std::endl;
	std::cout<<YELLOW<<"----- REF IDENTIFY ------"<<DEFAULT<<std::endl;
	Base	&base4 = *base1;
	Base	&base5 = *base2;
	Base	&base6 = *base3;
	std::cout<<"base4(*base1): ";
	identify(base4);
	std::cout<<"base5(*base2): ";
	identify(base5);
	std::cout<<"base6(*base3): ";
	identify(base6);

	std::cout<<std::endl;
	std::cout<<"base3: ";
	delete base3;
	std::cout<<"base2: ";
	delete base2;
	std::cout<<"base1: ";
	delete base1;
	return (0);
}

Base*	generate(void)
{
	int		random = rand() % 3;

	switch (random)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	default:
		return (new C);
	}
}

void	identify(Base *p)
{
	Base	*check;

	if (!(check = dynamic_cast<A*>(p)))
	{
		if (!(check = dynamic_cast<B*>(p)))
		{
			std::cout<<"C"<<std::endl;
			return ;
		}
		std::cout<<"B"<<std::endl;
		return ;
	}
	std::cout<<"A"<<std::endl;
}

void	identify(Base &p)
{
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout<<"A"<<std::endl;
	} catch (const std::exception &e) {
//	} catch (std::bad_cast &e) {
		try {
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout<<"B"<<std::endl;
		} catch (const std::exception &e) {
//		} catch (std::bad_cast &e) {
			std::cout<<"C"<<std::endl;
		}
	}
}
