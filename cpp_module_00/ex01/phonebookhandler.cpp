/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookhandler.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:57:16 by tjung             #+#    #+#             */
/*   Updated: 2022/03/23 22:04:49 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookhandler.hpp"

PhonebookHandler::PhonebookHandler(void) : list_cnt(0), list_num(0)
{
	std::cout<<"Called PhonebookHandler(void)"<<std::endl;
}

PhonebookHandler::~PhonebookHandler(void)
{
	std::cout<<"Called ~PhonebookHandler(void)"<<std::endl;
}

int		PhonebookHandler::CheckStrNum(std::string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
	}
	return (1);
}

void	PhonebookHandler::PutData(void)
{
	std::string	data;
	int			idx;

	idx = 1;
	while (idx <= 5)
	{
		std::cout<<FIELD_NAME[idx]<<": ";
		std::getline(std::cin, data);
		if (CheckStrNum(data))
		{
			phonebook[list_num].SetData(idx - 1, data);
			++idx;
		}
		else
			std::cout<<"* Only letters and numbers must be entered. *"<<std::endl;
	}
	std::cout<<std::endl;
}

void	PhonebookHandler::AddPhonebook(void)
{
	std::cout<<std::endl;
	std::cout<<"[ Add ]"<<std::endl;
	if (list_cnt < 8)
		++list_cnt;
	if (list_num == 8)
		list_num = 0;
	PutData();
	++list_num;
}

void	PhonebookHandler::ShowTenSrings(std::string &str) const
{
	std::cout.width(10); std::cout.fill(' ');
	if (str.length() > 10)
		std::cout<<str.substr(0, 9).append(1, '.');
	else
		std::cout<<str;
}

void	PhonebookHandler::ShowAllPhonebook(void)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout.width(10); std::cout.fill(' ');
		std::cout<<FIELD_NAME[i];
		if (i < 3)
			std::cout<<'|';
	}
	std::cout<<std::endl;
	for (int i = 0; i < list_cnt; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				std::cout.width(10); std::cout.fill(' ');
				std::cout<<i;
			}
			else
				ShowTenSrings(phonebook[i].GetData(j - 1));
			if (j < 3)
				std::cout<<'|';
		}
		std::cout<<std::endl;
	}
}

void	PhonebookHandler::ShowPhonebook(std::string &idx)
{
	int	num;

	try
	{
		num = std::stoi(idx);
		std::cout<<std::endl;
		for (int i = 0; i < 5; i++)
			std::cout<<FIELD_NAME[i + 1]<<": "<<phonebook[num].GetData(i)<<std::endl;
		std::cout<<std::endl;
	}
	catch (const std::exception& expn)
		{ std::cout<<expn.what()<< ": Invalid argument"<<std::endl; }
	catch (...)
		{ std::cout<<": Unknown error"<<std::endl; }
}

int	PhonebookHandler::CheckIndex(std::string &idx) const
{
	int	num;

	try
	{
		num = std::stoi(idx);
		if (num < list_cnt)
			return (1);
	}
	catch (const std::exception& expn)
		{ std::cout<<expn.what()<< ": Invalid argument"<<std::endl; }
	catch (...)
		{ std::cout<<": Unknown error"<<std::endl; }
	return (0);
}

void	PhonebookHandler::SearchPhonebook(void)
{
	std::string	cmd;

	std::cout<<std::endl;
	std::cout<<"[ Search ]"<<std::endl;
	ShowAllPhonebook();
	std::cout<<std::endl;
	std::cout<<"* put 'exit', exit Search *"<<std::endl;
	while (1)
	{
		std::cout<<"index: ";
		std::getline(std::cin, cmd);
		if (cmd == "exit")
		{
			std::cout<<"exit"<<std::endl<<std::endl;
			std::cout<<"[ PhoneBook ]"<<std::endl;
			break ;
		}
		else if (CheckIndex(cmd))
			ShowPhonebook(cmd);
	}
}
