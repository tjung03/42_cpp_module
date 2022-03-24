/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:57:09 by tjung             #+#    #+#             */
/*   Updated: 2022/03/23 17:50:15 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class	Phonebook
{
private:
	std::string	data[5];
public:
	Phonebook(void);
	~Phonebook(void);
	void		SetData(int field, std::string &str);
	std::string	&GetData(int field);
};

#endif
