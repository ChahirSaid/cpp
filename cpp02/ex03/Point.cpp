/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:38:28 by schahir           #+#    #+#             */
/*   Updated: 2025/12/10 09:38:29 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){}
Point::Point(float const x, float const y)
{
    _x = Fixed(x);
    _y = Fixed(y);
}
Point::~Point()
{
}
Point::Point(Point const &other)
{
    *this = other;
}
Point &Point::operator=(Point const &other)
{
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return (*this);
}

Fixed Point::get_X()const
{
    return (this->_x);
}
Fixed Point::get_Y()const
    {return (this->_y);
}