/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:14:31 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 04:43:50 by tjung            ###   ########.fr       */
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
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &ref);
	~Fixed(void);

	Fixed&	operator=(const Fixed &ref);
	bool	operator>(const Fixed &ref) const;
	bool	operator<(const Fixed &ref) const;
	bool	operator>=(const Fixed &ref) const;
	bool	operator<=(const Fixed &ref) const;
	bool	operator==(const Fixed &ref) const;
	bool	operator!=(const Fixed &ref) const;
	Fixed	operator+(const Fixed &ref);
	Fixed	operator-(const Fixed &ref);
	Fixed	operator*(const Fixed &ref);
	Fixed	operator/(const Fixed &ref);
	Fixed&	operator++(void);		// ++int
	Fixed	operator++(int);		// int++
	Fixed&	operator--(void);		// --int
	Fixed	operator--(int);		// int--

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed&		min(Fixed &ref1, Fixed &ref2);
	static const Fixed&	min(const Fixed &ref1, const Fixed &ref2);
	static Fixed&		max(Fixed &ref1, Fixed &ref2);
	static const Fixed&	max(const Fixed &ref1, const Fixed &ref2);
};

std::ostream&	operator<<(std::ostream &ostream_, const Fixed &ref);

#endif
