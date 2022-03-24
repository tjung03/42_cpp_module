#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club)
	: _name(name), _club(club)
{
	std::cout<<"Called HumanA(std::string name, Weapon &club)"<<std::endl;
}

HumanA::~HumanA(void)
{
	std::cout<<"Called ~HumanA(void)"<<std::endl;
}

void	HumanA::attack(void)
{
	std::cout<<_name<<" attacks with their "<<_club.getType()<<std::endl;
}
