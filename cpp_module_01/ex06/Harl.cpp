/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 03:57:32 by tjung             #+#    #+#             */
/*   Updated: 2022/03/25 04:24:09 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) { }

Harl::~Harl(void) { }

void	Harl::debug(void)
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."<<std::endl;
	std::cout<<"I really do!"<<std::endl<<std::endl;
}

void	Harl::info(void)
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl;
	std::cout<<"You didn’t put enough bacon in my burger!"<<std::endl;
	std::cout<<"If you did, I wouldn’t be asking for more!"<<std::endl<<std::endl;
}

void	Harl::warning(void)
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout<<"I’ve been coming for years whereas you started working here since last month."<<std::endl<<std::endl;
}

void	Harl::error(void)
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl<<std::endl;
}

void	Harl::complain(std::string level)
{
	int		idx = 0;

	for (; idx < 4 && (level != this->_level[idx]);)
		idx++;
	if (idx == 4)
	{
		std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
		return ;
	}
	(this->*_automateFunc[idx])();
}

int	Harl::getLevelIndex(std::string &level)
{
	int	idx = 0;

	for (; idx < 4 && (level != this->_level[idx]);)
		++idx;
	return (idx);
}
