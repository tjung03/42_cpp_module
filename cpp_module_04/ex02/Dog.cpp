/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:51:23 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:07:27 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout<<"Called Dog(void)"<<std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const std::string &type) : AAnimal(type)
{
	std::cout<<"Called Dog(const std::string &type)"<<std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &ref)
{
	std::cout<<"Called Dog(const Dog &ref)"<<std::endl;
	*this = ref;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout<<"Called ~Dog(void)"<<std::endl;
}

Dog&	Dog::operator=(const Dog &ref)
{
	this->setType(ref.getType());
	this->_brain = new Brain(*ref._brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout<<this->getType()<<": Baarrrkkkkk!!!!!"<<std::endl;
}

Brain	*Dog::getBrain(void)
{
	return (this->_brain);
}
