/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:59:04 by tjung             #+#    #+#             */
/*   Updated: 2022/03/25 22:38:23 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_number(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->_fixed_point_number = ref.getRawBits();
//	This line may be missing depending on your implementation
//	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed &ref)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->_fixed_point_number = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout<<"Destructor called"<<std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->_fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_number = raw;
}
