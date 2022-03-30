/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:11:22 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 09:18:44 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &ref);
	virtual ~Ice(void);

	Ice&	operator=(const Ice &ref);

	virtual AMateria*	clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif
