#include "Rect.h"


Rect::Rect(double sideA,double sideB,double rotationAngle,Point center): sideA{sideA},sideB{sideB},Figure(center),angle{rotationAngle}
{

}

double Rect::getArea() const
{
    return sideA*sideB;
}

double Rect::getPerimetr() const
{
    return 2*sideA+2*sideB;
}

void Rect::print() const
{
    std::cout<<"Center: "<<center<<std::endl;
    std::cout<<"Side A length: "<<sideA<<std::endl;
    std::cout<<"Side B length: "<<sideB<<std::endl;
    std::cout<<"Rotation angle: "<<angle;
}

// void Rect::generatePoints()
// {
    
// }