# ifndef POINT_HPP
# define  POINT_HPP

#include "Fixed.hpp"

class Point
{
    private :
        Fixed _x;
        Fixed _y;
    public :
        Point();
        Point(float const x, float const y);
        ~Point();
        Point(Point const &other);
        Point&operator=(Point const &other);

        Fixed get_X() const ;
        Fixed get_Y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif