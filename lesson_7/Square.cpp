#include "Square.hpp"


Square::Square(double side,double rotationAngle,Point center): Rect(side,side,rotationAngle,center)
{

}

// double Square::getArea() const
// {
//     return Rect::getArea();
// }

// double Square::getPerimetr() const
// {
//     return Rect::getPerimetr();
// }

void Square::print() const
{
    std::cout<<"Center: "<<center<<std::endl;
    std::cout<<"Square side: "<<sideA<<std::endl;
    std::cout<<"Rotaiton angle: "<<angle;
}