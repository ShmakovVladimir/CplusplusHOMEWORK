#include "Circle.h"

Circle::Circle(Point center,double radius): Ellipse(center,radius,radius)
{

}

void Circle::print() const 
{
    std::cout<<"Center: "<<center<<std::endl;
    std::cout<<"Radius: "<<radius1;
}