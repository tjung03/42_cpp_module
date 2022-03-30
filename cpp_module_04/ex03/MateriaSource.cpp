/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:41:36 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 15:15:04 by tjung            ###   ########.fr       */
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
		return ;
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
	{
		if ((this->_materia[i] != NULL) && (this->_materia[i]->getType() == type))
			return (this->_materia[i]->clone());
	}
	return (NULL);
}

void	MateriaSource::deleteMateria(AMateria* materia)
{
	if (materia != NULL)
		delete materia;
	materia = NULL;
}

std::string	MateriaSource::showMateriaArray(void) const
{
	for (int i = 0; i < MateriaSource::_MAX_MATERIA_SIZE; i++)
		std::cout<<i<<"". "
}
