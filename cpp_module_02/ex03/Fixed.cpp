/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:05:26 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 05:05:27 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_number(0) { }

Fixed::Fixed(const int val)
	: _fixed_point_number(val << Fixed::_fractional_bits)
{ }

Fixed::Fixed(const float val)
	: _fixed_point_number(static_cast<int>(roundf(val * (1 << Fixed::_fractional_bits))))
{ }

Fixed::Fixed(const Fixed &ref)
{
	*this = ref;
}

Fixed::~Fixed(void) { }

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_number = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_fixed_point_number);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixed_point_number) / (1 << Fixed::_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (_fixed_point_number >> Fixed::_fractional_bits);
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	return (ref2);
}

const Fixed&	Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	return (ref2);
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	return (ref2);
}

const Fixed&	Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	return (ref2);
}
