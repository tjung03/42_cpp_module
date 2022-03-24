/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:44:10 by tjung             #+#    #+#             */
/*   Updated: 2022/03/24 18:27:25 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	Zombie::_zomCnt = 0;

Zombie::Zombie(void)
{
	++Zombie::_zomCnt;
	std::cout<<"zom";
	std::cout.width(3); std::cout.fill(' ');
	std::cout<<getTotalZNum()<<"\tcreated"<<std::endl;
}

Zombie::Zombie(std::string &name) : _name(name)
{
	std::cout<<_name<<"\tcreated"<<std::endl;
}

Zombie::~Zombie(void)
{
	std::cout<<_name;
	std::cout.width(3); std::cout.fill(' ');
	std::cout<<_num<<"\tdied"<<std::endl;
}

void	Zombie::announce(void)
{
	std::cout<<_name;
	std::cout.width(3); std::cout.fill(' ');
	std::cout<<_num<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void	Zombie::setZomInfo(std::string &name, int num)
{
	this->_name = name;
	this->_num = num;
}

int	Zombie::getTotalZNum(void)
{
	return (Zombie::_zomCnt);
}
