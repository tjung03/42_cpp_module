/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:52:57 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:02:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "WrongBrain.hpp"

class	WrongCat : public WrongAnimal
{
private:
	WrongBrain	*_wrong;

public:
	WrongCat(void);
	WrongCat(const std::string &type);
	WrongCat(const WrongCat &ref);
	~WrongCat(void);

//	WrongCat&	operator=(const WrongCat &ref);

	void		makeSound(void) const;
	WrongBrain	*getBrain(void);
};

#endif
