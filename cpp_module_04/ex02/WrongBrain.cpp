/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:52:36 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 07:52:37 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongBrain.hpp"

WrongBrain::WrongBrain(void)
{
	std::cout<<"Called WrongBrain(void)"<<std::endl;
	this->_idea[0] = "0";
	for (int i = 1; i < 100; i++)
		this->_idea[i] = this->_idea[i - 1] + "0";
}

WrongBrain::WrongBrain(const WrongBrain &ref)
{
	std::cout<<"Called WrongBrain(const WrongBrain &ref)"<<std::endl;
	*this = ref;
}

WrongBrain::~WrongBrain(void)
{
	std::cout<<"Called ~WrongBrain(void)"<<std::endl;
}

WrongBrain&	WrongBrain::operator=(const WrongBrain &ref)
{
	for (int i = 0; i < 100; i++)
		this->_idea[i] = ref._idea[i];
	return (*this);
}

void	WrongBrain::ShowTenIdea(void) const
{
	for (int i = 0; i < 10; i++)
		std::cout<<this->_idea[i]<<std::endl;
}
