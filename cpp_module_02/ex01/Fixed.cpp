/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:27:22 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 00:05:43 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_number(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int val)
	: _fixed_point_number(val << Fixed::_fractional_bits)
{
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float val)
	: _fixed_point_number(static_cast<int>(roundf(val * (1 << Fixed::_fractional_bits))))
{
	std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed &ref)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	_fixed_point_number = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout<<"Destructor called"<<std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_number = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixed_point_number) / (1 << Fixed::_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (_fixed_point_number >> Fixed::_fractional_bits);
}

std::ostream&	operator<<(std::ostream &ostream_, const Fixed &ref)
{
	ostream_ << ref.toFloat();
	return (ostream_);
}
