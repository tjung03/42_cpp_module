#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _club(NULL)
{
	std::cout<<"Called HumanB(std::string name)"<<std::endl;
}

HumanB::~HumanB(void)
{
	std::cout<<"Called ~HumanB(void)"<<std::endl;
}

void	HumanB::setWeapon(Weapon &club)
{
	this->_club = &club;
}

void	HumanB::attack(void)
{
	if (_club)
		std::cout<<_name<<" attacks with their "<<_club->getType()<<std::endl;
	else
		std::cout<<_name<<" has no weapons to attack"<<std::endl;
}
