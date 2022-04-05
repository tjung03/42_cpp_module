#include <iostream>
#include "Span.hpp"

#define YELLOW "\e[33m"
#define DEFAULT "\e[0m"

int	main(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout<<std::endl;
	std::cout<<YELLOW<<"====== TEST ======="<<DEFAULT<<std::endl;
	std::cout<<"---- exception ----"<<std::endl;
	std::cout<<" [sp - add: full]"<<std::endl;
	try {
		sp.addNumber(20);
		std::cout<<"-> add success"<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	Span	test(3);
	std::cout<<" [test - span: zero]"<<std::endl;
	try {
		std::cout<<"shortest: "<<test.shortestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		std::cout<<"longest: "<<test.longestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	std::cout<<" [test - span: one]"<<std::endl;
	test.addNumber(10);
	try {
		std::cout<<"shortest: "<<test.shortestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		std::cout<<"longest: "<<test.longestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	std::cout<<" [test - span: two]"<<std::endl;
	test.addNumber(20);
	try {
		std::cout<<"shortest: "<<test.shortestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		std::cout<<"longest: "<<test.longestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	std::cout<<"---- range add ----"<<std::endl;
	std::cout<<" [big 1]"<<std::endl;
	Span	big1(10001);
	for (int i = 0; i < 10001; ++i)
		big1.addNumber(i);
	try {
		std::cout<<"shortest: "<<big1.shortestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		std::cout<<"longest: "<<big1.longestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	Span	big2(10001);
	try {
		big2.addNumber(big1.getVector().begin(), big1.getVector().end());
		std::cout<<"-> range add success"<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"----- repeat ------"<<std::endl;
	std::cout<<" [big 2]"<<std::endl;
	try {
		std::cout<<"shortest: "<<big2.shortestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		std::cout<<"longest: "<<big2.longestSpan()<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	return (0);
}