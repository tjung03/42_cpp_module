/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:14:39 by tjung             #+#    #+#             */
/*   Updated: 2022/03/23 12:16:49 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string	input(argv[i]);
			for (int j = 0; input[j] != '\0'; j++)
				std::cout<<(char)toupper(input[j]);
		}
		std::cout<<std::endl;
	}
	return (0);
}
