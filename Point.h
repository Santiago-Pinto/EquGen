#ifndef POINT_H
#define POINT_H
#include "Rational_Number.h"

class Point{
    private:
       rationalNumber& x_coord;
       rationalNumber& y_coord;

    public:
        Point(rationalNumber& x, rationalNumber& y);
        rationalNumber get_x();
        rationalNumber get_y();

        //Used to get a slope for a linear expression
        rationalNumber operator -(const Point& other);
};



#endif // POINT_H
