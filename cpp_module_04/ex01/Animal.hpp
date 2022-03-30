/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:58:02 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
# define Animal_HPP

#include <iostream>
#include <string>

class	Animal
{
protected:
	std::string	_type;

public:
	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &ref);
	virtual ~Animal(void);

	Animal&	operator=(const Animal &ref);

	virtual void	makeSound(void) const;

	std::string	getType(void) const;
	void		setType(const std::string &type);
};

#endif
