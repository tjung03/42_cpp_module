/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:06:56 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 20:31:49 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("AMateria")
{
	std::cout<<"Called AMateria(void)"<<std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout<<"Called AMateria(std::string const &type)"<<std::endl;
}

AMateria::AMateria(const AMateria &ref)
{
	std::cout<<"Called AMateria(const AMateria &ref)"<<std::endl;
	*this = ref;
}

AMateria::~AMateria(void)
{
	std::cout<<"Called ~AMateria(void)"<<std::endl;
}

AMateria&	AMateria::operator=(const AMateria &ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::setType(const std::string &type)
{
	this->_type = type;
}

void	use(ICharacter& target)
{
	std::cout<<"use(): "<<target.getName()<< std::endl;
}
