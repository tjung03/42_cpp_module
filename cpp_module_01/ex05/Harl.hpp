/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:39:59 by tjung             #+#    #+#             */
/*   Updated: 2022/03/25 03:48:36 by tjung            ###   ########.fr       */
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

	std::string	_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*_automateFunc[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);
};

#endif
