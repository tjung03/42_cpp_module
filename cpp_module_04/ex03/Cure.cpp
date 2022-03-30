/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:23:37 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 09:18:23 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout<<"Called Cure(void)"<<std::endl;
}

Cure::Cure(const Cure &ref)
{
	std::cout<<"Called Cure(const Cure &ref)"<<std::endl;
	*this = ref;
}

Cure::~Cure(void)
{
	std::cout<<"Called ~Cure(void)"<<std::endl;
}

Cure&	Cure::operator=(const Cure &ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}
