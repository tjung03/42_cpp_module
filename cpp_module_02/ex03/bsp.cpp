/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:07:39 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 21:33:06 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	점 point 의 y 좌표는 두 선분 꼭지점의 y 좌표 사이에 있다.
//	점 point 를 지나는 수평선과 선분 사이의 교점의 x 좌표는 점 point 의 x 좌표보다 크다.
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cross_pnt;
	int		cross_cnt = 0;

	// a-b
	if ((point.get_y() < a.get_y()) != point.get_y() < b.get_y())
	{
		cross_pnt = ((b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) / (b.get_y() - a.get_y())) + a.get_x();
		if (point.get_x() < cross_pnt)
			++cross_cnt;
	}
	// a-c
	if ((point.get_y() < a.get_y()) != point.get_y() < c.get_y())
	{
		cross_pnt = ((c.get_x() - a.get_x()) * (point.get_y() - a.get_y()) / (c.get_y() - a.get_y())) + a.get_x();
		if (point.get_x() < cross_pnt)
			++cross_cnt;
	}
	// b-c
	if ((point.get_y() < b.get_y()) != point.get_y() < c.get_y())
	{
		cross_pnt = ((c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) / (c.get_y() - b.get_y())) + b.get_x();
		if (point.get_x() < cross_pnt)
			++cross_cnt;
	}
	return (cross_cnt % 2 == 1);
}
