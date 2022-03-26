/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:05:51 by tjung             #+#    #+#             */
/*   Updated: 2022/03/26 22:01:41 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a_point(0, 5);
	Point	o_point(0, 0);
	Point	b_point(5, 0);
	Point	internal(1, 1);
	Point	external(5, 5);

	// 삼각형 aob
	std::cout<<"<triangle aob>"<<std::endl;
	std::cout<<"a_point("<<a_point.get_x()<<", "<<a_point.get_y()<<")"<<std::endl;
	std::cout<<"o_point("<<o_point.get_x()<<", "<<o_point.get_y()<<")"<<std::endl;
	std::cout<<"b_point("<<b_point.get_x()<<", "<<b_point.get_y()<<")"<<std::endl;
	std::cout<<std::endl;
	// 삼각형 aob 의 내부, 외부 판별
	std::cout<<"<Determine whether point is an internal>"<<std::endl;
	std::cout<<"internal("<<internal.get_x()<<", "<<internal.get_y()<<")";
	if (bsp(a_point, o_point, b_point, internal))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	std::cout<<"<Determine whether point is an external>"<<std::endl;
	std::cout<<"external("<<external.get_x()<<", "<<external.get_y()<<")";
	if (bsp(a_point, o_point, b_point, external))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	return (0);
}
