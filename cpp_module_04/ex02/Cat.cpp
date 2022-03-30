/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:51:10 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:07:14 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout<<"Called Cat(void)"<<std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const std::string &type) : AAnimal(type)
{
	std::cout<<"Called Cat(const std::string &type)"<<std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &ref)
{
	std::cout<<"Called Cat(const Cat &ref)"<<std::endl;
	*this = ref;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout<<"Called ~Cat(void)"<<std::endl;
}

Cat&	Cat::operator=(const Cat &ref)
{
	this->setType(ref.getType());
	this->_brain = new Brain(*ref._brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout<<this->getType()<<": Meow Meow"<<std::endl;
}

Brain	*Cat::getBrain(void)
{
	return (this->_brain);
}
