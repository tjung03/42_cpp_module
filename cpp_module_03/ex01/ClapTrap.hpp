/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:45:40 by tjung             #+#    #+#             */
/*   Updated: 2022/03/28 00:29:34 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define DEFAULT "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define CYAN "\e[36m"

typedef unsigned int	uint;

class	ClapTrap
{
private:

	std::string		_name;
	uint			_hit_points;
	uint			_energy_points;
	uint			_attack_damage;

public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &ref);
	virtual ~ClapTrap(void);
	ClapTrap&	operator=(const ClapTrap &ref);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName(void) const;
	uint		getHitPoints(void) const;
	uint		getEnergyPoints(void) const;
	uint		getAttackDamage(void) const;

	const void		setName(const std::string &name);
	void		setHitPoints(const uint set);
	void		setEnergyPoints(const uint set);
	void		setAttackDamage(const uint set);
};

#endif
