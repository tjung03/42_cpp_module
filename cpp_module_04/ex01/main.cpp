/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:58:38 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	delete i;
	delete j;//should not create a leak

	std::cout<<std::endl;
	const Animal	*Animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			Animals[i] = new Cat();
		else
			Animals[i] = new Dog();
	}
	for (int i = 3; i >= 0; i--)
		delete Animals[i];

	std::cout<<std::endl;
	Cat *origin = new Cat("Origin");
	Cat copy(*origin);
	std::cout<<"-> origin Brain: "<<origin->getBrain()<<std::endl;
	origin->getBrain()->ShowTenIdea();
	delete origin;
	std::cout<<"-> copy Brain: "<<copy.getBrain()<<std::endl;;
	copy.getBrain()->ShowTenIdea();
	WrongCat *worigin = new WrongCat("WOrigin");
	WrongCat wcopy(*worigin);
	std::cout<<"-> worigin Brain: "<<worigin->getBrain()<<std::endl;
	worigin->getBrain()->ShowTenIdea();
	delete worigin;
	std::cout<<"-> wcopy Brain: "<<wcopy.getBrain()<<std::endl;;
	wcopy.getBrain()->ShowTenIdea();
	return (0);
}