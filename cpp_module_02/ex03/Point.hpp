/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:07:46 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 18:58:45 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
private:
	const Fixed	_x;
	const Fixed	_y;

public:
	Point(void);
	Point(const float xpos, const float ypos);
	Point(const Point &ref);
	~Point(void);
	Point&	operator=(const Point &ref);
	Fixed	get_x(void) const;
	Fixed	get_y(void) const;
};

bool			bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream&	operator<<(std::ostream &ostream_, const Point &ref);

#endif
