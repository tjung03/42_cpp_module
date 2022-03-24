/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 03:57:41 by tjung             #+#    #+#             */
/*   Updated: 2022/03/25 04:21:16 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	std::string	level;
	int			filter;
	Harl		harl;

	if (argc != 2)
	{
		std::cout<<"Invalid number of arguments!"<<std::endl;
		return (1);
	}
	level = argv[1];
	filter = harl.getLevelIndex(level);
	switch (filter)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break ;
	default:
		harl.complain(level);
	}
	return (0);
}
