/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:45:56 by tjung             #+#    #+#             */
/*   Updated: 2022/03/27 23:31:19 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ShowScavTrapStatus(const ScavTrap &ref)
{
	std::cout<<"< STATUS >"<<std::endl;
	std::cout<<"ScavTrap "<<ref.getName();
	std::cout<<" (hit: "<<ref.getHitPoints()<<", energy: "<<ref.getEnergyPoints()<<", damage: "<<ref.getAttackDamage()<<")";
	std::cout<<std::endl;
}

int	main(void)
{
	ScavTrap	attacker("I");
	ScavTrap	defender("You");
	int			attack_cnt = 0;
	bool		flag = false;

	std::cout<<std::endl;
	ShowScavTrapStatus(attacker);
	ShowScavTrapStatus(defender);
	std::cout<<std::endl;
	for (; defender.getHitPoints() != 0;)
	{
		if (attack_cnt > 7 && flag == true)
		{
			std::cout<<"ScavTrap "<<defender.getName()<<" Gate keeper mode off!"<<std::endl;
			defender.setGateKeeperMode(false);
			flag = false;
		}
		if (defender.getHitPoints() < 30 && defender.getGateKeeperMode() == false && attack_cnt < 7)
		{
			defender.guardGate();
			flag = true;
		}
		attacker.attack("You");
		attack_cnt++;
		defender.takeDamage(attacker.getAttackDamage());
		ShowScavTrapStatus(defender);
		defender.beRepaired(1);
		if (defender.getHitPoints() != 0)
			ShowScavTrapStatus(defender);
		std::cout<<std::endl;
	}
	ShowScavTrapStatus(attacker);
	ShowScavTrapStatus(defender);
	std::cout<<std::endl;
	return (0);
}
