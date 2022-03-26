/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:59:29 by tjung             #+#    #+#             */
/*   Updated: 2022/03/25 21:23:48 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
private:
	int					_fixed_point_number;
	static const int	_fractional_bits;

public:
	Fixed(void);
	Fixed(const Fixed &ref);
	~Fixed(void);
	Fixed&	operator=(const Fixed &ref);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
