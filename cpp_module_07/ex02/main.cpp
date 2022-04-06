#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0m"

int	main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int	value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
		std::cout<<"numbers array addr: "<<numbers.getArrPtr()<<std::endl;
		std::cout<<"mirror array addr: "<<mirror<<std::endl;
		std::cout<<"tmp array addr: "<<tmp.getArrPtr()<<std::endl;
		std::cout<<"test array addr: "<<test.getArrPtr()<<std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (numbers[i] != test[i])
			{
				std::cerr << "if(numbers[i] != test[i]): didn't save the same value!!" << std::endl;
				return (1);
			}
			if (tmp[i] != test[i])
			{
				std::cerr << "if(tmp[i] != test[i]): didn't save the same value!!" << std::endl;
				return (1);
			}
		}
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "if(mirror[i] != numbers[i]): didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		if (mirror[i] != numbers[i])
		{
			std::cerr << "if(mirror[i] != numbers[i]): didn't save the same value!!" << std::endl;
			break ;
		}
	}
	delete []mirror;//

	std::cout<<YELLOW<<"===== TEST ======="<<DEFAULT<<std::endl;
	const unsigned int	N = 5;
	unsigned int		size;

	std::cout<<"--- DEEP COPY ----"<<std::endl;
	Array<int> 		arr1(N);	// 배열 생성

	size = arr1.size();
	for (unsigned int i = 0; i < size; i++)
		arr1[i] = i;

	Array<int>	arr2(arr1);		// 복사 생성자 사용

	size = arr2.size();
	for (unsigned int i = 0; i < size; i++)
		arr2[i] = i + N;

	std::cout<<"-> [modify arr2 value]"<<std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout<<"arr1["<<i<<"]: "<<arr1[i]<<std::endl;
	std::cout<<std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout<<"arr2["<<i<<"]: "<<arr2[i]<<std::endl;

	std::cout<<std::endl;
	for (unsigned int i = 0; i < size; i++)
		arr1[i] = i - N;
	std::cout<<"-> [modify arr1 value]"<<std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout<<"arr1["<<i<<"]: "<<arr1[i]<<std::endl;
	std::cout<<std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout<<"arr2["<<i<<"]: "<<arr2[i]<<std::endl;

	std::cout<<std::endl;
	std::cout<<"--- OUT OF BOUNDS ----"<<std::endl;
	Array<float>	arr3(N);

	size = arr3.size();
	for (unsigned int i = 1; i < size; i++)
		arr3[i] = arr3[i - 1] + 10.1;
	for (unsigned int i = 0; i < size; i++)
		std::cout<<"arr3["<<i<<"]: "<<arr3[i]<<std::endl;

	std::cout<<std::endl;
	try {
		(void)arr3[-1];
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<": [-1]: * out of bounds *"<<std::endl;
	}

	std::cout<<std::endl;
	try {
		(void)arr3[N];
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<": [N]:  * out of bounds *"<<std::endl;
	}
	return (0);
}
