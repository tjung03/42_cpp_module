/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:45:29 by tjung             #+#    #+#             */
/*   Updated: 2022/03/30 09:23:03 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	static const int	_MAX_INVENTORY_SIZE;
	AMateria			*_inventory[4];

public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &ref);
	virtual ~Character(void);

	Character&	operator=(const Character &ref);

	virtual std::string const &	getName(void) const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter &target);

	void	deleteMateria(AMateria *materia);
};

#endif
