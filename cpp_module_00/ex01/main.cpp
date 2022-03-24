/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:57:19 by tjung             #+#    #+#             */
/*   Updated: 2022/03/23 17:59:33 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookhandler.hpp"

int	main(int argc, char *argv[])
{
	PhonebookHandler	handler;
	std::string			cmd;

	std::cout<<"[ PhoneBook ]"<<std::endl;
	while (1)
	{
		std::cout<<"> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			handler.AddPhonebook();
		else if (cmd == "SEARCH")
			handler.SearchPhonebook();
		else if (cmd == "EXIT")
		{
			std::cout<<"exit"<<std::endl;
			break ;
		}
	}
	return (0);
}
