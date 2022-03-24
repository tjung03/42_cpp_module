/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookhandler.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:57:13 by tjung             #+#    #+#             */
/*   Updated: 2022/03/23 21:40:36 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKHANDLER_HPP
# define PHONEBOOKHANDLER_HPP

# include "phonebook.hpp"
# include <cstring>

class	PhonebookHandler
{
private:
	Phonebook	phonebook[8];
	int			list_cnt;
	int			list_num;

	std::string	FIELD_NAME[6] = {
		"index",
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};

public:
	PhonebookHandler(void);
	~PhonebookHandler(void);
	int		CheckStrNum(std::string &str);
	void	PutData(void);
	void	AddPhonebook(void);
	void	ShowTenSrings(std::string &str) const;
	void	ShowAllPhonebook(void);
	void	ShowPhonebook(std::string &idx);
	int		CheckIndex(std::string &idx) const;
	void	SearchPhonebook(void);
};

#endif
