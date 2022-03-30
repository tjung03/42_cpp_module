/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:50:35 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:03:29 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout<<"Called AAnimal(void)"<<std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	std::cout<<"Called AAnimal(const std::string &type)"<<std::endl;
}

AAnimal::AAnimal(const AAnimal &ref)
{
	std::cout<<"Called AAnimal(const AAnimal &ref)"<<std::endl;
	*this = ref;
}

AAnimal::~AAnimal(void)
{
	std::cout<<"Called ~AAnimal(void)"<<std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &ref)
{
	this->setType(ref.getType());
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout<<"AAnimal's makeSound()"<<std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(const std::string &type)
{
	this->_type = type;
}
