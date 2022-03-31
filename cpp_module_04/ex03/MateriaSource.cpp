/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:41:36 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 10:56:06 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

const int	MateriaSource::_MAX_MATERIA_SIZE = 4;

MateriaSource::MateriaSource(void)
{
	std::cout<<"Called MateriaSource(void)"<<std::endl;
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	std::cout<<"Called MateriaSource(const MateriaSource &ref)"<<std::endl;
	*this = ref;
}

MateriaSource::~MateriaSource(void)
{
	std::cout<<"Called ~MateriaSource(void)"<<std::endl;
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
			this->deleteMateria(this->_materia[i]);
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
		{
			this->deleteMateria(this->_materia[i]);
			if (ref._materia[i] != NULL)
				this->_materia[i] = ref._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cout<<"* learnMateria(): no learning *"<<std::endl;
		return ;
	}
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia->clone();
			delete materia;
			return ;
		}
	}
	std::cout<<"* learnMateria(): MateriaSource full *"<<std::endl;
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
	{
		if ((this->_materia[i] != NULL) && (this->_materia[i]->getType() == type))
			return (this->_materia[i]->clone());
	}
	std::cout<<"* createMateria(): no learing or no fit *"<<std::endl;
	return (0);
}

void	MateriaSource::deleteMateria(AMateria* materia)
{
	if (materia != NULL)
		delete materia;
	materia = NULL;
}

void	MateriaSource::deleteMateriaSource(const int idx, const std::string &type)
{
	if ((this->_materia[idx] != NULL) && (this->_materia[idx]->getType() == type))
	{
		std::cout<<"* MateriaSource ["<<idx<<"] "<<this->_materia[idx]->getType()<<" delete *"<<std::endl;
		deleteMateria(this->_materia[idx]);
		return ;
	}
	std::cout<<"* deleteMateriaSource(): invalid arguments *"<<std::endl;
}

void	MateriaSource::showMateriaArray(void) const
{
	std::cout<<"[ Materia ]"<<std::endl;
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
	{
		if (this->_materia[i] != NULL)
		{
			std::cout<<" "<<this->_materia[i]->getType();
			if ((this->_materia[i + 1] != NULL) && (i + 1 < MateriaSource::_MAX_MATERIA_SIZE))
				std::cout<<"\t";
		}
	}
	std::cout<<std::endl;
}
