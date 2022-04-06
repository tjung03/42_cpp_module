#include "iter.hpp"

#define YELLOW "\033[0;33m"
#define DEFAULT "\033[0m"

int	main(void)
{
	std::cout<<YELLOW<<"----- TEST ------"<<DEFAULT<<std::endl;
	std::cout<<"[ INT ARRAY1 ]"<<std::endl;
	int	*arr1 = new int[3];
	for (int i = 0; i < 3; i++)
		arr1[i] = i;
	::iter(arr1, 3, printArrElements);
	delete arr1;
	std::cout<<std::endl<<std::endl;
	std::cout<<"[ INT ARRAY2 ]"<<std::endl;
	int	arr2[3];
	for (int i = 0; i < 3; i++)
		arr2[i] = i;
	std::cout<<std::endl;
	::iter(arr2, 3, addNumOfArrElements);
	::iter(arr2, 3, printArrElements);
	std::cout<<std::endl<<std::endl;
	std::cout<<"[ FLOAT ARRAY ]"<<std::endl;
	float	arr3[3];
	for (int i = 0; i < 3; i++)
		arr3[i] = i + 0.5;
	::iter(arr3, 3, addNumOfArrElements);
	::iter(arr3, 3, printArrElements);
	std::cout<<std::endl<<std::endl;
	std::cout<<"[ DOUBLE ARRAY ]"<<std::endl;
	double	arr4[3];
	for (int i = 0; i < 3; i++)
		arr4[i] = i + 0.1;
	::iter(arr4, 3, subNumofArrElements);
	::iter(arr4, 3, printArrElements);
	std::cout<<std::endl<<std::endl;
	std::cout<<"[ PTR ARRAY ]"<<std::endl;
	int	a = 10;
	int	b = 100;
	int	c = 1000;
	int	*parr[3] = { &a, &b, &c };
	::iter(parr, 3, printArrElements);
	::iter(parr, 3, printPtrArrElements);
	std::cout<<std::endl<<std::endl;
	std::cout<<"[ STRING ARRAY ]"<<std::endl;
	std::string	sarr[3] = { "happiness", "joy", "glory" };
	::iter(sarr, 3, addStrOfArrElements);
	::iter(sarr, 3, printArrElements);
	std::cout<<std::endl;
	return (0);
}
