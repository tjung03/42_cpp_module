#include "easyfind.hpp"
#include <vector>
#include <string>

# define YELLOW "\e[33m"
# define DEFAULT "\e[0m"

int	main(void)
{
	std::cout<<YELLOW<<"===== TEST ======="<<DEFAULT<<std::endl;
	std::cout<<"------ INT -------"<<std::endl;
	std::vector<int>			vi(10);
	std::vector<int>::size_type	vi_origin_size = vi.size();
	for (std::vector<int>::size_type i = 0; i < vi_origin_size; i++)
		vi[i] = i;
	printContainer(vi);
	std::cout<<std::endl;

	std::cout<<std::endl;
	printEasyFind(vi, 0);
	printEasyFind(vi, 5);
	printEasyFind(vi, 10);

	std::cout<<std::endl;
	std::cout<<"----- FLOAT -----"<<std::endl;
	std::vector<float>			vf(7);
	std::vector<float>::size_type	vf_origin_size = vf.size();
	for (std::vector<float>::size_type i = 0; i < vf_origin_size; i++)
		vf[i] = i + 0.1f;
	printContainer(vf);
	std::cout<<std::endl;

	vf[5] = 5.0f;

	std::cout<<std::endl;
	printEasyFind(vf, 5);
	printEasyFind(vf, 1);

	std::cout<<std::endl;
	printContainer(vf);
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"---- DOUBLE -----"<<std::endl;
	std::vector<double>			vd(5);
	std::vector<double>::size_type	vd_origin_size = vd.size();
	for (std::vector<double>::size_type i = 0; i < vd_origin_size; i++)
		vd[i] = i + 0.5;
	printContainer(vd);
	std::cout<<std::endl;

	vd[3] = 7.0;

	std::cout<<std::endl;
	printEasyFind(vd, 7);
	printEasyFind(vd, 3);

	std::cout<<std::endl;
	printContainer(vd);
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"---- STRING -----"<<std::endl;
	std::vector<std::string>			vs(3);
	vs[0] = "Hi";
	vs[1] = "Umm..";
	vs[2] = "Bye";
	printContainer(vs);
	std::cout<<std::endl;

	std::cout<<std::endl;
	printEasyFind(vd, 1);

	std::cout<<std::endl;
	std::cout<<YELLOW<<"==== RELEASE ====="<<DEFAULT<<std::endl;
	vi.clear();
	vf.clear();
	vd.clear();
	vs.clear();
	std::vector<int>().swap(vi);
	std::vector<float>().swap(vf);
	std::vector<double>().swap(vd);
	std::vector<std::string>().swap(vs);
	return (0);
}