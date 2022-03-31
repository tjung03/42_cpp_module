/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:19:13 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 11:09:00 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout<<std::endl<<"=============== more ==============="<<std::endl<<std::endl;

	src = new MateriaSource();
	std::cout<<std::endl;
	src->learnMateria(NULL);
	std::cout<<std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout<<std::endl;
	src->learnMateria(new Ice());

	std::cout<<std::endl;
	src->showMateriaArray();

	std::cout<<std::endl;
	me = new Character("me");

	std::cout<<std::endl;
	me->equip(NULL);

	std::cout<<std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout<<std::endl;
	me->unequip(2);

	std::cout<<std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout<<std::endl;
	me->unequip(3);

	std::cout<<std::endl;
	std::cout<<"\e[33m< inventory && temp_room >\e[0m"<<std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout<<std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout<<std::endl;
	me->showInventoryArray();

	std::cout<<std::endl;
	bob = new Character("bob");

	std::cout<<std::endl;
	me->use(-1, *bob);
	std::cout<<std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout<<std::endl;
	me->unequip(3);
	std::cout<<std::endl;
	me->use(3, *bob);

	std::cout<<std::endl;
	delete bob;
	delete me;
	delete src;

	return (0);
}