/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedOperator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 03:50:49 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 04:56:28 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&	Fixed::operator=(const Fixed &ref)
{
	_fixed_point_number = ref.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &ref) const
{
	return (_fixed_point_number > ref._fixed_point_number);
}

bool	Fixed::operator<(const Fixed &ref) const
{
	return (_fixed_point_number < ref._fixed_point_number);
}

bool	Fixed::operator>=(const Fixed &ref) const
{
	return (_fixed_point_number >= ref._fixed_point_number);
}

bool	Fixed::operator<=(const Fixed &ref) const
{
	return (_fixed_point_number <= ref._fixed_point_number);
}

bool	Fixed::operator==(const Fixed &ref) const
{
	return (_fixed_point_number == ref._fixed_point_number);
}

bool	Fixed::operator!=(const Fixed &ref) const
{
	return (_fixed_point_number != ref._fixed_point_number);
}

Fixed	Fixed::operator+(const Fixed &ref)
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &ref)
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &ref)
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &ref)
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed&	Fixed::operator++(void)		// ++int
{
	++this->_fixed_point_number;
	return (*this);
}

Fixed	Fixed::operator++(int)		// int++
{
	const Fixed	copy(*this);

	this->_fixed_point_number++;
	return (copy);
}

Fixed&	Fixed::operator--(void)		// --int
{
	--this->_fixed_point_number;
	return (*this);
}

Fixed	Fixed::operator--(int)		// int--
{
	const Fixed	copy(*this);

	this->_fixed_point_number--;
	return (copy);
}
