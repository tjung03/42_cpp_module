/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:52:14 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 00:25:12 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	ShowFragTrapStatus(const FragTrap &ref)
{
	std::cout<<"< STATUS >"<<std::endl;
	std::cout<<"FragTrap "<<ref.getName();
	std::cout<<" (hit: "<<ref.getHitPoints()<<", energy: "<<ref.getEnergyPoints()<<", damage: "<<ref.getAttackDamage()<<")";
	std::cout<<std::endl;
}

int	main(void)
{
	FragTrap	attacker("I");
	FragTrap	defender("You");

	std::cout<<std::endl;
	ShowFragTrapStatus(attacker);
	ShowFragTrapStatus(defender);
	std::cout<<std::endl;
	attacker.highFivesGuys();
	defender.highFivesGuys();
	std::cout<<std::endl;
	for (; defender.getHitPoints() != 0;)
	{
		attacker.attack("You");
		defender.takeDamage(attacker.getAttackDamage());
		ShowFragTrapStatus(defender);
		defender.beRepaired(1);
		if (defender.getHitPoints() != 0)
			ShowFragTrapStatus(defender);
		std::cout<<std::endl;
	}
	ShowFragTrapStatus(attacker);
	ShowFragTrapStatus(defender);
	std::cout<<std::endl;
	return (0);
}
