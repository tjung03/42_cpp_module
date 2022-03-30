/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:57:54 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout<<"Called Animal(void)"<<std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout<<"Called Animal(const std::string &type)"<<std::endl;
}

Animal::Animal(const Animal &ref)
{
	std::cout<<"Called Animal(const Animal &ref)"<<std::endl;
	*this = ref;
}

Animal::~Animal(void)
{
	std::cout<<"Called ~Animal(void)"<<std::endl;
}

Animal&	Animal::operator=(const Animal &ref)
{
	this->setType(ref.getType());
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout<<"Animal's makeSound()"<<std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}
