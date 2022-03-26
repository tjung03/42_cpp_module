/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:57:11 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 04:51:12 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	std::cout<<"Called Phonebook(void)"<<std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout<<"Called ~Phonebook(void)"<<std::endl;
}

void	Phonebook::SetData(int field, std::string &str)
{
	data[field] = str;
}

std::string	&Phonebook::GetData(int field)
{
	std::string	&str = data[field];
	return (str);
}
