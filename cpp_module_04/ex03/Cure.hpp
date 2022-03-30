/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:46 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 09:18:03 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &ref);
	virtual ~Cure(void);

	Cure&	operator=(const Cure &ref);

	virtual AMateria*	clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif
