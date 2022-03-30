/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:09 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 09:20:48 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout<<"Called Ice(void)"<<std::endl;
}

Ice::Ice(const Ice &ref)
{
	std::cout<<"Called Ice(const Ice &ref)"<<std::endl;
	*this = ref;
}

Ice::~Ice(void)
{
	std::cout<<"Called ~Ice(void)"<<std::endl;
}

Ice&	Ice::operator=(const Ice &ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
