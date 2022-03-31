/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:33:49 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 10:59:30 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

const int	Character::_MAX_INVENTORY_SIZE = 4;


Character::Character(void) : _name("Character")
{
	std::cout<<"Called Character(void)"<<std::endl;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
		this->_temp_room[i] = NULL;
	}
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout<<"Called Character(const std::string &name)"<<std::endl;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
		this->_temp_room[i] = NULL;
	}
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
	{
		if (this->_inventory[i] != this->_temp_room[i])
			this->deleteMateria(this->_temp_room[i]);
		this->deleteMateria(this->_inventory[i]);
	}
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
	{
		std::cout<<"* equip(): not get anything *"<<std::endl;
		return ;
	}
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			if (this->_temp_room[i] != NULL)
				this->deleteMateria(this->_temp_room[i]);
			this->_inventory[i] = m;
			this->_temp_room[i] = m;
			std::cout<<"-> Success equip"<<std::endl;
			return ;
		}
	}
	std::cout<<"-> I didn't do anything."<<std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < Character::_MAX_INVENTORY_SIZE)
	{
		if (this->_inventory[idx] != NULL)
		{
			this->_inventory[idx] = NULL;
			std::cout<<"-> Success unequip"<<std::endl;
		}
		else
			std::cout<<"-> I didn't do anything."<<std::endl;
	}
	else
		std::cout<<"* unequip(): invalied arguments *"<<std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < Character::_MAX_INVENTORY_SIZE)
	{
		if (this->_inventory[idx] != NULL)
		{
			this->_inventory[idx]->use(target);
			return ;
		}
	}
	else
	{
		std::cout<<"* Character::use(): invalid arguments *"<<std::endl;
		return ;
	}
	std::cout<<"-> I didn't do anything."<<std::endl;
}

void	Character::showInventoryArray(void) const
{
	std::cout<<"[ "<<this->getName()<<"'s Inventory ]"<<std::endl;
	for (int i = 0; i < Character::_MAX_INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			std::cout<<" "<<this->_inventory[i]->getType();
			if ((this->_inventory[i + 1] != NULL) && (i + 1 < Character::_MAX_INVENTORY_SIZE))
				std::cout<<"\t";
		}
	}
	std::cout<<std::endl;
}

void	Character::deleteMateria(AMateria *materia)
{
	if (materia != NULL)
		delete materia;
	materia = NULL;
}
