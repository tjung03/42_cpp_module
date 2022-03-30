/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:52:56 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 07:47:23 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGBRAIN_HPP
# define WRONGBRAIN_HPP

# include <iostream>
# include <string>

class	WrongBrain
{
private:
	std::string	_idea[100];

public:
	WrongBrain(void);
	WrongBrain(const WrongBrain &ref);
	virtual ~WrongBrain(void);

	WrongBrain&	operator=(const WrongBrain &ref);

	void	ShowTenIdea(void) const;
};

#endif
