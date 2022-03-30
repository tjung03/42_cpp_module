/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:33:49 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 09:23:08 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

const int	_MAX_INVENTORY_SIZE = 4;


Character::Character(void) : _name("Character")
{
	std::cout<<"Called Character(void)"<<std::endl;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout<<"Called Character(const std::string &name)"<<std::endl;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &ref)
{
	std::cout<<"Called Character(const Character &ref)"<<std::endl;
	*this = ref;
}

Character::~Character(void)
{
	std::cout<<"Called ~Character(void)"<<std::endl;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
		this->deleteMateria(this->_inventory[i]);
}

Character&	Character::operator=(const Character &ref)
{
	if (this != &ref)
	{
		this->_name = ref.getName();
		for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
		{
			this->deleteMateria(this->_inventory[i]);
			if (ref._inventory[i] != NULL)
				this->_inventory[i] = ref._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < this->_MAX_INVENTORY_SIZE)
	{
		if (this->_inventory[idx] != NULL)
			deleteMateria(this->_inventory[idx]);
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < this->_MAX_INVENTORY_SIZE)
	{
		if (this->_inventory[idx] != NULL)
			this->_inventory[idx]->use(target);
	}
}

void	Character::deleteMateria(AMateria *materia)
{
	if (materia != NULL)
		delete materia;
	materia = NULL;
}
