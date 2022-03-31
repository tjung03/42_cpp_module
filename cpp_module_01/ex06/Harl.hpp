/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 03:57:23 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 15:24:49 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	std::string	_level[4];
	void		(Harl::*_automateFunc[4])(void);

public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);
	int		getLevelIndex(std::string &level);
};

#endif
