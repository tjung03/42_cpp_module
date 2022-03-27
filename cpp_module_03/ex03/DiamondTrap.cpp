/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:39:50 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 04:32:44 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	DiamondTrap::setName(ClapTrap::getName());
	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	this->ClapTrap::setEnergyPoints(50);
	this->ScavTrap::setGateKeeperMode(false);
	std::cout<<"Called DiamondTrap(void): "<<this->DiamondTrap::getName()<<std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	ClapTrap::getName().erase(name.length(), 10);
	DiamondTrap::setName(ClapTrap::getName().erase(name.length(), 10));
//	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	this->ClapTrap::setEnergyPoints(50);
	this->ScavTrap::setGateKeeperMode(false);
	std::cout<<"Called DiamondTrap(const std::string &name): "<<this->DiamondTrap::getName()<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref)
{
	*this = ref;
	std::cout<<"Called DiamondTrap(const DiamondTrap &ref): "<<this->DiamondTrap::getName()<<std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout<<"Called ~DiamondTrap(void): "<<this->DiamondTrap::getName()<<std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->ClapTrap::setName(ref.ClapTrap::getName());
	this->ClapTrap::setHitPoints(ref.ClapTrap::getHitPoints());
	this->ClapTrap::setEnergyPoints(ref.ClapTrap::getEnergyPoints());
	this->ClapTrap::setAttackDamage(ref.ClapTrap::getAttackDamage());
	this->ScavTrap::setGateKeeperMode(ref.ScavTrap::getGateKeeperMode());
	this->DiamondTrap::setName(ref.DiamondTrap::getName());
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout<<RED<<"[DiamondTrap "<<this->DiamondTrap::getName()<<"]"<<std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	int	health;

	if (this->ScavTrap::getGateKeeperMode())
	{
		std::cout<<BLUE<<"DiamondTrap "<<this->DiamondTrap::getName()<<" didn't suffer any damage."<<DEFAULT<<std::endl;
		return ;
	}
	std::cout<<YELLOW;
	std::cout<<"DiamondTrap "<<this->DiamondTrap::getName()<<" suffered "<<amount<<" points of damage."<<std::endl;
	std::cout<<DEFAULT;
	health = this->ClapTrap::getHitPoints() - amount;
	if (health < 0)
		health = 0;
	this->ClapTrap::setHitPoints(health);
	if (this->ClapTrap::getHitPoints() == 0)
		std::cout<<CYAN<<"DiamondTrap "<<this->DiamondTrap::getName()<<" died."<<DEFAULT<<std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (!this->ClapTrap::getHitPoints() || !this->ClapTrap::getEnergyPoints())
		return ;
	std::cout<<GREEN;
	std::cout<<"DiamondTrap "<<this->DiamondTrap::getName()<<" repaired "<<amount<<" points of hit."<<std::endl;
	std::cout<<DEFAULT;
	this->ClapTrap::setHitPoints(this->ClapTrap::getHitPoints() + amount);
	this->ClapTrap::setEnergyPoints(this->ClapTrap::getEnergyPoints() - 1);
}

void	DiamondTrap::guardGate(void)
{
	std::cout<<BLUE<<"DiamondTrap "<<this->DiamondTrap::getName()<<" GATE KEEPER MODE ON!"<<DEFAULT<<std::endl;
	this->ScavTrap::setGateKeeperMode(true);
}

void	DiamondTrap::highFivesGuys(void)
{
	std::cout<<PURPLE<<"DiamondTrap "<<this->DiamondTrap::getName()<<" request a positive high fives!"<<DEFAULT<<std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout<<"* DiamondTrap name is "<<DiamondTrap::getName()<<", ClapTrap name is "<<ClapTrap::getName()<<" *"<<std::endl;
}

const void	DiamondTrap::setName(const std::string &name)
{
	this->DiamondTrap::_name = name;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->DiamondTrap::_name);
}
