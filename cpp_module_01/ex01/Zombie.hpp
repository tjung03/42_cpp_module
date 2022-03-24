/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:44:00 by tjung             #+#    #+#             */
/*   Updated: 2022/03/24 18:21:00 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
private:
	std::string	_name;
	int			_num;
	static int	_zomCnt;

public:
	Zombie(void);
	Zombie(std::string &name);
	~Zombie(void);
	void	announce(void);
	void	setZomInfo(std::string &name, int num);
	int		getTotalZNum(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
