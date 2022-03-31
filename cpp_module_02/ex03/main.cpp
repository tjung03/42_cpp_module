/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:05:51 by tjung             #+#    #+#             */
/*   Updated: 2022/03/31 19:44:25 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a_point(0, 5);
	Point	b_point(0, 0);
	Point	c_point(5, 0);
	Point	internal1(1, 1);
	Point	internal2(2, 2);
	Point	external1(0, 0);
	Point	external2(1, 0);
	Point	external3(0, 1);
	Point	external4(5, 5);

	// 삼각형 aob
	std::cout<<"<triangle abc>"<<std::endl;
	std::cout<<"a_point("<<a_point.get_x()<<", "<<a_point.get_y()<<")"<<std::endl;
	std::cout<<"b_point("<<b_point.get_x()<<", "<<b_point.get_y()<<")"<<std::endl;
	std::cout<<"c_point("<<c_point.get_x()<<", "<<c_point.get_y()<<")"<<std::endl;
	std::cout<<std::endl;
	// 삼각형 aob 의 내부, 외부 판별
	std::cout<<"<Determine whether point is an internal>"<<std::endl;
	std::cout<<"internal1("<<internal1.get_x()<<", "<<internal1.get_y()<<")";
	if (bsp(a_point, b_point, c_point, internal1))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	std::cout<<std::endl<<"<Determine whether point is an internal>"<<std::endl;
	std::cout<<"internal2("<<internal2.get_x()<<", "<<internal2.get_y()<<")";
	if (bsp(a_point, b_point, c_point, internal2))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	std::cout<<std::endl<<"<Determine whether point is an external>"<<std::endl;
	std::cout<<"external1("<<external1.get_x()<<", "<<external1.get_y()<<")";
	if (bsp(a_point, b_point, c_point, external1))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	std::cout<<std::endl<<"<Determine whether point is an external>"<<std::endl;
	std::cout<<"external2("<<external2.get_x()<<", "<<external2.get_y()<<")";
	if (bsp(a_point, b_point, c_point, external2))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	std::cout<<std::endl<<"<Determine whether point is an external>"<<std::endl;
	std::cout<<"external3("<<external3.get_x()<<", "<<external3.get_y()<<")";
	if (bsp(a_point, b_point, c_point, external3))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	std::cout<<std::endl<<"<Determine whether point is an external>"<<std::endl;
	std::cout<<"external4("<<external4.get_x()<<", "<<external4.get_y()<<")";
	if (bsp(a_point, b_point, c_point, external4))
		std::cout<<" located inside"<<std::endl;
	else
		std::cout<<" located outside"<<std::endl;
	return (0);
}
