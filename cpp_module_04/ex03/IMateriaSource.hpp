/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:39:36 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 08:18:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_CPP
# define IMATERIASOURCE_CPP

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource(void) {};
	virtual void		learnMateria(AMateria *materia) = 0;
	virtual AMateria*	createMateria(std::string const &type) = 0;
	virtual void		showMateriaArray(void) const = 0;
};

#endif
