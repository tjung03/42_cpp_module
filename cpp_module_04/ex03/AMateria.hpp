/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:04:38 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 22:23:08 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &ref);
	virtual ~AMateria(void);

	AMateria&	operator=(const AMateria &ref);

	std::string const &	getType(void) const; //Returns the materia type
	void				setType(const std::string &type);

	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);
};


#endif
