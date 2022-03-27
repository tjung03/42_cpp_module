/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:34:03 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 04:37:49 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	ShowDiamondTrapStatus(const DiamondTrap &ref)
{
	std::cout<<"< STATUS >"<<std::endl;
	std::cout<<"DiamondTrap "<<ref.getName();
	std::cout<<" (hit: "<<ref.getHitPoints()<<", energy: "<<ref.getEnergyPoints()<<", damage: "<<ref.getAttackDamage()<<")";
	std::cout<<std::endl;
}

int	main(void)
{
	DiamondTrap	attacker("attacker");
	DiamondTrap	defender("defender");\
	int			attack_cnt = 0;
	bool		flag = false;

	std::cout<<std::endl;
	ShowDiamondTrapStatus(attacker);
	ShowDiamondTrapStatus(defender);
	std::cout<<std::endl;
	attacker.highFivesGuys();
	defender.highFivesGuys();
	std::cout<<std::endl;
	for (; defender.getHitPoints() != 0;)
	{
		if (attack_cnt > 7 && flag == true)
		{
			std::cout<<"DiamondTrap "<<defender.getName()<<" Gate keeper mode off!"<<std::endl;
			defender.setGateKeeperMode(false);
			flag = false;
		}
		if (defender.getHitPoints() < 30 && defender.getGateKeeperMode() == false && attack_cnt < 7)
		{
			defender.guardGate();
			flag = true;
		}
		attacker.attack("defender");
		attack_cnt++;
		defender.takeDamage(attacker.getAttackDamage());
		ShowDiamondTrapStatus(defender);
		defender.beRepaired(1);
		if (defender.getHitPoints() != 0)
			ShowDiamondTrapStatus(defender);
		std::cout<<std::endl;
	}
	ShowDiamondTrapStatus(attacker);
	ShowDiamondTrapStatus(defender);
	std::cout<<std::endl;
	attacker.whoAmI();
	defender.whoAmI();
	std::cout<<std::endl;
	return (0);
}
