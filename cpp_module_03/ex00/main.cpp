/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:22:30 by tjung             #+#    #+#             */
/*   Updated: 2022/03/27 00:54:57 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ShowStatus(const ClapTrap &ref)
{
	std::cout<<"< STATUS >"<<std::endl;
	std::cout<<"ClapTrap "<<ref.getName();
	std::cout<<" (hit: "<<ref.getHitPoints()<<", energy: "<<ref.getEnergyPoints()<<", damage: "<<ref.getAttackDamage()<<")";
	std::cout<<std::endl;
}

int	main(void)
{
	ClapTrap	attacker("I");
	ClapTrap	defender("You");

	std::cout<<std::endl;
	ShowStatus(attacker);
	ShowStatus(defender);
	std::cout<<std::endl;
	std::cout<<attacker.getName()<<" gained three points in offense!"<<std::endl;
	attacker.setAttackDamage(3);
	ShowStatus(attacker);
	std::cout<<std::endl;
	for (; defender.getHitPoints() != 0;)
	{
		attacker.attack("You");
		defender.takeDamage(attacker.getAttackDamage());
		ShowStatus(defender);
		defender.beRepaired(1);
		if (defender.getHitPoints() != 0)
			ShowStatus(defender);
		std::cout<<std::endl;
	}
	ShowStatus(attacker);
	ShowStatus(defender);
	std::cout<<std::endl;
	return (0);
}
