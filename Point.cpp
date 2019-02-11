#include "Point.h"

Point::Point(rationalNumber& x, rationalNumber& y): x_coord(x), y_coord(y){
    //ctor
}


rationalNumber  Point::get_x(){
    return this->x_coord;
}


rationalNumber Point::get_y(){

    return this->y_coord;
}


rationalNumber Point::operator -(const Point& other){

    rationalNumber num = this->y_coord - other.y_coord;
    rationalNumber den = this->x_coord - other.x_coord;
    return (num/den);
}
