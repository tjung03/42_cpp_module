/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:43:53 by tjung             #+#    #+#             */
/*   Updated: 2022/03/24 18:23:10 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N = 10;

	horde = zombieHorde(N, "zom");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
