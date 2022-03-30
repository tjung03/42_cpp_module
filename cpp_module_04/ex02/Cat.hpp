/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:51:17 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:07:20 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
{
private:
	Brain	*_brain;

public:
	Cat(void);
	Cat(const std::string &type);
	Cat(const Cat &ref);
	virtual ~Cat(void);

	Cat&	operator=(const Cat &ref);

	void	makeSound(void) const;
	Brain	*getBrain(void);
};

#endif
