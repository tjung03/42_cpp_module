/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:52:06 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 04:03:43 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(""), _gate_keeper_mode(false)
{
	std::cout<<"Called ScavTrap(void): "<<this->getName()<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _gate_keeper_mode(false)
{
	std::cout<<"Called ScavTrap(const std::string &name): "<<this->getName()<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &ref)
{
	*this = ref;
	std::cout<<"Called ScavTrap(const ScavTrap &ref): "<<this->getName()<<std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout<<"Called ~ScavTrap(void): "<<this->getName()<<std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &ref)
{
	this->ClapTrap::operator=(ref);
	this->setGateKeeperMode(ref.getGateKeeperMode());
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
		return ;
	std::cout<<RED;
	std::cout<<"ScavTrap "<<this->getName()<<" attacks "<<target;
	std::cout<<", causing "<<this->getAttackDamage()<<" points of damage!"<<std::endl;
	std::cout<<DEFAULT;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	int	health;

	if (this->_gate_keeper_mode)
	{
		std::cout<<BLUE<<"ScavTrap "<<this->getName()<<" didn't suffer any damage."<<DEFAULT<<std::endl;
		return ;
	}
	std::cout<<YELLOW;
	std::cout<<"ScavTrap "<<this->getName()<<" suffered "<<amount<<" points of damage."<<std::endl;
	std::cout<<DEFAULT;
	health = this->getHitPoints() - amount;
	if (health < 0)
		health = 0;
	this->setHitPoints(health);
	if (this->getHitPoints() == 0)
		std::cout<<CYAN<<"ScavTrap "<<this->getName()<<" died."<<DEFAULT<<std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
		return ;
	std::cout<<GREEN;
	std::cout<<"ScavTrap "<<this->getName()<<" repaired "<<amount<<" points of hit."<<std::endl;
	std::cout<<DEFAULT;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate(void)
{
	std::cout<<BLUE<<"ScavTrap "<<this->getName()<<" GATE KEEPER MODE ON!"<<DEFAULT<<std::endl;
	this->setGateKeeperMode(true);
}

bool	ScavTrap::getGateKeeperMode(void) const
{
	return (this->_gate_keeper_mode);
}

void	ScavTrap::setGateKeeperMode(const bool mode)
{
	this->_gate_keeper_mode = mode;
}
