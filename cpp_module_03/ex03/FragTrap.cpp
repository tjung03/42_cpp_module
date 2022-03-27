/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:33:46 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 04:02:31 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout<<"Called FragTrap(void): "<<this->getName()<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout<<"Called FragTrap(const std::string &name): "<<this->getName()<<std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &ref)
{
	*this = ref;
	std::cout<<"Called FragTrap(const FragTrap &ref): " <<this->getName()<<std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout<<"Called ~FragTrap(void): "<<this->getName()<<std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &ref)
{
	this->ClapTrap::operator=(ref);
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
		return ;
	std::cout<<RED;
	std::cout<<"FragTrap "<<this->getName()<<" attacks "<<target;
	std::cout<<", causing "<<this->getAttackDamage()<<" points of damage!"<<std::endl;
	std::cout<<DEFAULT;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	int	health;

	std::cout<<YELLOW;
	std::cout<<"FragTrap "<<this->getName()<<" suffered "<<amount<<" points of damage."<<std::endl;
	std::cout<<DEFAULT;
	health = this->getHitPoints() - amount;
	if (health < 0)
		health = 0;
	this->setHitPoints(health);
	if (this->getHitPoints() == 0)
		std::cout<<CYAN<<"FragTrap "<<this->getName()<<" died."<<DEFAULT<<std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
		return ;
	std::cout<<GREEN;
	std::cout<<"FragTrap "<<this->getName()<<" repaired "<<amount<<" points of hit."<<std::endl;
	std::cout<<DEFAULT;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout<<PURPLE<<"FragTrap "<<this->getName()<<" request a positive high fives!"<<DEFAULT<<std::endl;
}
