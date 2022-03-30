/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:51:30 by tjung             #+#    #+#             */
/*   Updated: 2022/03/29 08:07:31 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
private:
	Brain	*_brain;

public:
	Dog(void);
	Dog(const std::string &type);
	Dog(const Dog &ref);
	virtual ~Dog(void);

	Dog&	operator=(const Dog &ref);

	void	makeSound(void) const;
	Brain	*getBrain(void);
};

#endif
