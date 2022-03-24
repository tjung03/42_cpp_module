/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:43:38 by tjung             #+#    #+#             */
/*   Updated: 2022/03/24 17:13:57 by tjung            ###   ########.fr       */
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

public:
	Zombie(std::string &name);
	~Zombie(void);
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
