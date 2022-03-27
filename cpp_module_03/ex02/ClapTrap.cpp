/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:51:48 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 03:13:12 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout<<"Called ClapTrap(void): "<<this->getName()<<std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout<<"Called ClapTrap(const std::string &name): "<<this->getName()<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	*this = ref;
	std::cout<<"Called ClapTrap(const ClapTrap &ref): "<<this->getName()<<std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout<<"Called ~ClapTrap(void): "<<this->getName()<<std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ref)
{
	this->_name = ref.getName();
	this->_hit_points = ref.getHitPoints();
	this->_energy_points = ref.getEnergyPoints();
	this->_attack_damage = ref.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
		return ;
	std::cout<<RED;
	std::cout<<"ClapTrap "<<this->getName()<<" attacks "<<target;
	std::cout<<", causing "<<this->getAttackDamage()<<" points of damage!"<<std::endl;
	std::cout<<DEFAULT;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	health;

	std::cout<<YELLOW;
	std::cout<<"ClapTrap "<<this->getName()<<" suffered "<<amount<<" points of damage."<<std::endl;
	std::cout<<DEFAULT;
	health = this->getHitPoints() - amount;
	if (health < 0)
		health = 0;
	this->setHitPoints(health);
	if (this->getHitPoints() == 0)
		std::cout<<CYAN<<"ClapTrap "<<this->getName()<<" died."<<DEFAULT<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
		return ;
	std::cout<<GREEN;
	std::cout<<"ClapTrap "<<this->getName()<<" repaired "<<amount<<" points of hit."<<std::endl;
	std::cout<<DEFAULT;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

uint	ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

uint	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

uint	ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}

const void	ClapTrap::setName(const std::string &name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(const uint set)
{
	this->_hit_points = set;
}

void	ClapTrap::setEnergyPoints(const uint set)
{
	this->_energy_points = set;
}

void	ClapTrap::setAttackDamage(const uint set)
{
	this->_attack_damage = set;
}
