/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:38:34 by schahir           #+#    #+#             */
/*   Updated: 2025/12/10 11:15:57 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


long crossproduct( Point const i, Point const j, Point const p)
{
        //(p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
        
      return ((i.get_X().getRawBits() - p.get_X().getRawBits()) *(j.get_Y().getRawBits() - p.get_Y().getRawBits()) - (j.get_X().getRawBits()- p.get_X().getRawBits()) * (i.get_Y().getRawBits() - p.get_Y().getRawBits()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    long d1, d2, d3;
    d1 = crossproduct(a, b, point);
    d2 = crossproduct(b, c, point);
    d3 = crossproduct(c, a, point);

    if ((d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0))
        return (1);
    return (0);
}