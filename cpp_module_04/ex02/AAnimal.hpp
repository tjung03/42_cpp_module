/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:50:45 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:03:33 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>
#include <string>

class	AAnimal
{
protected:
	std::string	_type;

public:
	AAnimal(void);
	AAnimal(const std::string &type);
	AAnimal(const AAnimal &ref);
	virtual ~AAnimal(void);

	AAnimal&	operator=(const AAnimal &ref);

	virtual void	makeSound(void) const = 0;

	std::string		getType(void) const;
	void			setType(const std::string &type);
};

#endif
