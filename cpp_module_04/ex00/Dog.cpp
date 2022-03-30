/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:05:18 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout<<"Called Dog(void)"<<std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout<<"Called Dog(const std::string &type)"<<std::endl;
}

Dog::Dog(const Dog &ref)
{
	*this = ref;
	std::cout<<"Called Dog(const Dog &ref)"<<std::endl;
}

Dog::~Dog(void)
{
	std::cout<<"Called ~Dog(void)"<<std::endl;
}

Dog&	Dog::operator=(const Dog &ref)
{
	this->setType(ref.getType());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout<<this->getType()<<": Baarrrkkkkk!!!!!"<<std::endl;
}
