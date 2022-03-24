/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:43:41 by tjung             #+#    #+#             */
/*   Updated: 2022/03/24 18:11:54 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string &name) : _name(name)
{
	std::cout<<_name<<" created"<<std::endl;
}

Zombie::~Zombie(void)
{
	std::cout<<_name<<" died"<<std::endl;
}

void	Zombie::announce(void)
{
	std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
