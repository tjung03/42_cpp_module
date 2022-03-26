/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:06:10 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 09:04:58 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream&	operator<<(std::ostream &ostream_, const Fixed &ref)
{
	ostream_ << ref.toFloat();
	return (ostream_);
}

std::ostream&	operator<<(std::ostream &ostream_, const Point &ref)
{
	ostream_ << "(" << ref.get_x() << ", " << ref.get_y() << ")";
	return (ostream_);
}
