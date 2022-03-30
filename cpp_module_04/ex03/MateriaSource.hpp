/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:47:53 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 08:36:52 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CPP
# define MATERIASOURCE_CPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int	_MAX_MATERIA_SIZE;
	AMateria			*_materia[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &ref);
	virtual ~MateriaSource(void);

	MateriaSource&	operator=(const MateriaSource &ref);

	virtual void		learnMateria(AMateria *materia);
	virtual AMateria*	createMateria(std::string const & type);

	void	deleteMateria(AMateria *materia);
};

#endif
