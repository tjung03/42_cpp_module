#include "Array.hpp"

# define YELLOW "\e[33m"
# define DEFAULT "\e[0m"

int	main(void)
{
	const unsigned int	N = 5;
	unsigned int		size;

	std::cout<<YELLOW<<"===== TEST ======="<<DEFAULT<<std::endl;
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
