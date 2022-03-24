/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:30:17 by tjung             #+#    #+#             */
/*   Updated: 2022/03/24 18:44:30 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string_ = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string_;
	std::string	&stringREF = string_;

	std::cout<<"The memory address of the string variable:\t";
	std::cout<<&string_<<std::endl;
	std::cout<<"The memory address held by stringPTR:\t\t";
	std::cout<<stringPTR<<std::endl;
	std::cout<<"The memory address held by stringREF:\t\t";
	std::cout<<&stringREF<<std::endl<<std::endl;
	std::cout<<"And then:"<<std::endl<<std::endl;
	std::cout<<"The value of the string variable:\t";
	std::cout<<string_<<std::endl;
	std::cout<<"The value pointed to by stringPTR:\t";
	std::cout<<*stringPTR<<std::endl;
	std::cout<<"The value pointed to by stringREF:\t";
	std::cout<<stringREF<<std::endl;
	return (0);
}
