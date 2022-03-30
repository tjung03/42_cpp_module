/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:05:06 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout<<"Called Cat(void)"<<std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout<<"Called Cat(const std::string &type)"<<std::endl;
}

Cat::Cat(const Cat &ref)
{
	*this = ref;
	std::cout<<"Called Cat(const Cat &ref)"<<std::endl;
}

Cat::~Cat(void)
{
	std::cout<<"Called ~Cat(void)"<<std::endl;
}

Cat&	Cat::operator=(const Cat &ref)
{
	this->setType(ref.getType());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout<<this->getType()<<": Meow Meow"<<std::endl;
}
