/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:50:55 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 07:50:55 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout<<"Called Brain(void)"<<std::endl;
	this->_idea[0] = "0";
	for (int i = 1; i < 100; i++)
		this->_idea[i] = this->_idea[i - 1] + "0";
}

Brain::Brain(const Brain &ref)
{
	std::cout<<"Called Brain(const Brain &ref)"<<std::endl;
	*this = ref;
}

Brain::~Brain(void)
{
	std::cout<<"Called ~Brain(void)"<<std::endl;
}

Brain&	Brain::operator=(const Brain &ref)
{
	for (int i = 0; i < 100; i++)
		this->_idea[i] = ref._idea[i];
	return (*this);
}

void	Brain::ShowTenIdea(void) const
{
	for (int i = 0; i < 10; i++)
		std::cout<<this->_idea[i]<<std::endl;
}
