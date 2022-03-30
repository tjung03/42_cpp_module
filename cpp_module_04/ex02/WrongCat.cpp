/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:52:50 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout<<"Called WrongCat(void)"<<std::endl;
	this->_wrong = new WrongBrain();
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout<<"Called WrongCat(const std::string &type)"<<std::endl;
	this->_wrong = new WrongBrain();
}

WrongCat::WrongCat(const WrongCat &ref)
{
	std::cout<<"Called WrongCat(const WrongCat &ref)"<<std::endl;
	*this = ref;
}

WrongCat::~WrongCat(void)
{
	delete this->_wrong;
	std::cout<<"Called ~WrongCat(void)"<<std::endl;
}

/*
WrongCat&	WrongCat::operator=(const WrongCat &ref)
{
	this->setType(ref.getType());
	this->_wrong = new WrongBrain(*ref._wrong);
	return (*this);
}
*/

void	WrongCat::makeSound(void) const
{
	std::cout<<this->getType()<<": Meow Meow"<<std::endl;
}

WrongBrain	*WrongCat::getBrain(void)
{
	return (this->_wrong);
}
