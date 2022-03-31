/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:07:39 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 19:42:07 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	checkFunc(const Point p1, const Point p2, const Point target, int *cross_cnt)
{
	Fixed cross_pnt;
	
	if ((target.get_y() < p1.get_y()) != target.get_y() < p2.get_y())
	{
		cross_pnt = ((p2.get_x() - p1.get_x()) * (target.get_y() - p1.get_y()) / (p2.get_y() - p1.get_y())) + p1.get_x();
		if (cross_pnt == target.get_x())
			return (false);
		if (target.get_x() < cross_pnt)
			++(*cross_cnt);
	}
	return (true);
}

//	점 point 의 y 좌표는 두 선분 꼭지점의 y 좌표 사이에 있다.
//	점 point 를 지나는 수평선과 선분 사이의 교점의 x 좌표는 점 point 의 x 좌표보다 크다.
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cross_pnt;
	int		cross_cnt = 0;

	// a-b
	if (!checkFunc(a, b, point, &cross_cnt))
		return (false);
	if (a.get_y() == b.get_y() && a.get_y() == point.get_y())
		return (false);
	// a-c
	if (!checkFunc(a, c, point, &cross_cnt))
		return (false);
	if (a.get_y() == c.get_y() && a.get_y() == point.get_y())
		return (false);
	// b-c
	if (!checkFunc(b, c, point, &cross_cnt))
		return (false);
	if (b.get_y() == c.get_y() && b.get_y() == point.get_y())
		return (false);
	return (cross_cnt % 2 == 1);
}
