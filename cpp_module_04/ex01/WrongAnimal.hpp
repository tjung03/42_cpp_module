/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:59:06 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAnimal_HPP
# define WRONGAnimal_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
protected:
	std::string	_type;

public:
	WrongAnimal(void);
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &ref);
	virtual ~WrongAnimal(void);

	WrongAnimal&	operator=(const WrongAnimal &ref);

	void	makeSound(void) const;

	std::string	getType(void) const;
	void		setType(const std::string &type);
};

#endif
