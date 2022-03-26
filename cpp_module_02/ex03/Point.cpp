/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:07:54 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 12:13:49 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) { }

Point::Point(const float xpos, const float ypos)
	: _x(Fixed(xpos)), _y(Fixed(ypos))
{ }

Point::Point(const Point &ref)
	: _x(ref._x), _y(ref._y)
{ }

Point::~Point(void) { }

Point&	Point::operator=(const Point &ref)
{
	const_cast<Fixed&>(this->_x) = ref.get_x();
	const_cast<Fixed&>(this->_y) = ref.get_y();
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (this->_x);
}

Fixed	Point::get_y(void) const
{
	return (this->_y);
}
