/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:59:00 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout<<"Called WrongAnimal(void)"<<std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout<<"Called WrongAnimal(const std::string &type)"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout<<"Called WrongAnimal(const WrongAnimal &ref)"<<std::endl;
	*this = ref;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout<<"Called ~WrongAnimal(void)"<<std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &ref)
{
	this->setType(ref.getType());
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout<<"WrongAnimal's makeSound()"<<std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}
