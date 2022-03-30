/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:55:43 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout<<"Called WrongCat(void)"<<std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout<<"Called WrongCat(const std::string &type)"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
	*this = ref;
	std::cout<<"Called WrongCat(const WrongCat &ref)"<<std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout<<"Called ~WrongCat(void)"<<std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &ref)
{
	this->setType(ref.getType());
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout<<this->getType()<<": Meow Meow"<<std::endl;
}
