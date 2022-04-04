#include "Data.hpp"

Data::Data(void) { }

Data::Data(const Data &rhs)
{
	*this = rhs;
}
Data::~Data(void) { }

Data&	Data::operator=(const Data &rhs)
{
	if (this != &rhs)
		this->setArguments(rhs.getString(), rhs.getInteger());
	return (*this);
}

uintptr_t	Data::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Data::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

void	Data::setArguments(const std::string &str, const int num)
{
	this->_str = str;
	this->_num = num;
}

std::string	Data::getString(void) const
{
	return (this->_str);
}

int	Data::getInteger(void) const
{
	return (this->_num);
}
