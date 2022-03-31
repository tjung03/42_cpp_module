/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:39:55 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 15:28:39 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		std::cout<<"Invalid number of arguments!"<<std::endl;
		return (1);
	}
	
	Harl	harl;
	
	std::cout<<std::endl<<"start"<<std::endl<<std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");
	std::cout<<"end"<<std::endl<<std::endl;
	return (0);
}
