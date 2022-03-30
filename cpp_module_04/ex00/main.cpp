/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:47:06 by tjung             #+#    #+#             */
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
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout<<std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout<<std::endl;
	delete i; delete j; delete meta;
	std::cout<<std::endl;

	const WrongAnimal	*wrong_Animal = new WrongAnimal();
	const WrongAnimal	*wrong_cat = new WrongCat();

	std::cout<<std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_cat->makeSound();
	wrong_Animal->makeSound();

	std::cout<<std::endl;
	delete wrong_cat; delete wrong_Animal;
	return (0);
}