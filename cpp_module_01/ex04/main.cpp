/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:25 by tjung             #+#    #+#             */
/*   Updated: 2022/03/25 02:23:24 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#define	INVALID_NUM_ARGU "Invalid number of arguments"
#define	INVALID_ARGUMENT "Invalid arguments"
#define NO_OPEN_FILE "The file could not open"

int	perror_msg(std::string str)
{
	std::cout<<str<<std::endl;
	return (1);
}

int	isok_arguments(const char *s1, const char *s2)
{
	std::string str1(s1), str2(s2);

	if (str2.find(str1) != std::string::npos)
		return (0);
	return (1);
}

void	closed_file(std::ifstream &rfile, std::ofstream &wfile)
{
	if (rfile.is_open())
		rfile.close();
	if (wfile.is_open())
		wfile.close();
}

void	replace_string(std::string &line, const char *s1, const char *s2)
{
	std::string::size_type	start_pos;
	std::string	replace;
	std::string	str1(s1), str2(s2);

	start_pos = line.find(str1);
	if (start_pos == std::string::npos)
		return ;
	while (start_pos != std::string::npos)
	{
		replace = line.substr(0, start_pos);
		replace += str2;
		replace += line.substr(start_pos + str1.length());
		line = replace;
		start_pos = line.find(str1);
	}
}

int	main(int argc, char *argv[])
{
	std::string		fname;
	std::ifstream	rfile;
	std::ofstream	wfile;
	std::string		line;
	std::string		name;

	if (argc != 4)
		return (perror_msg(INVALID_NUM_ARGU));
	if (!isok_arguments(argv[2], argv[3]))
		return (perror_msg(INVALID_ARGUMENT));
	fname = argv[1];
	rfile.open(fname);
	if (!rfile.is_open())
		return (perror_msg(NO_OPEN_FILE));
	name = fname;
	for (int i = 0; i < fname.length(); i++)
	{
		if (fname[i] == '.')
		{
			name = fname.substr(0, i);
			break ;
		}
	}
	wfile.open(name + ".replace");
	if (!wfile.is_open())
	{
		closed_file(rfile, wfile);
		return (perror_msg(NO_OPEN_FILE));
	}
	while (getline(rfile, line))
	{
		replace_string(line, argv[2], argv[3]);
		wfile<<line<<std::endl;
	}
	closed_file(rfile, wfile);
	return (0);
}
