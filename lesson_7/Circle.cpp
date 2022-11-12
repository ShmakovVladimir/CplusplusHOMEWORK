#include "Circle.h"

Circle::Circle(Point center,double radius): Ellipse(center,0,radius,radius)
{

}

void Circle::print() const 
{
    std::cout<<"Center: "<<center<<std::endl;
    std::cout<<"Radius: "<<radius1;
}

// double Circle::getArea() const
// {
//     return Ellipse::getArea();
// }

// double Circle::getPerimetr() const
// {
//     return Ellipse::getPerimetr();
// }