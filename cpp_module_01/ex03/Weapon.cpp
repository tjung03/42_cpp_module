#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: _type(type)
{
	std::cout<<"Called Weapon(std::string type)"<<std::endl;
}

Weapon::~Weapon(void)
{
	std::cout<<"Called ~Weapon(void)"<<std::endl;
}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}

void		Weapon::setType(std::string type)
{
	this->_type = type;
}
