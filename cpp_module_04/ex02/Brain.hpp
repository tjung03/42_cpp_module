/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:51:02 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 07:51:02 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
private:
	std::string	_idea[100];

public:
	Brain(void);
	Brain(const Brain &ref);
	virtual ~Brain(void);

	Brain&	operator=(const Brain &ref);

	void	ShowTenIdea(void) const;
};

#endif
