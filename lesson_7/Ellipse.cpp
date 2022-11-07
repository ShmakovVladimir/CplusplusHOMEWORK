#include "Ellipse.h"

Ellipse::Ellipse(Point center,double rotationAngle,double radius1,double radius2): center{center},radius1{radius1},radius2{radius2},angle{rotationAngle}
{

}

void Ellipse::print() const
{
    std::cout<<"Center: "<<center<<std::endl;
    std::cout<<"Big semiaxis: "<<std::max(radius1,radius2)<<std::endl;
    std::cout<<"Small semiaxis: "<<std::min(radius1,radius2)<<std::endl;
    std::cout<<"Rotation angle: "<<angle;
}

double Ellipse::getArea() const
{
    return PI*radius1*radius2;
}

double Ellipse::getPerimetr() const
{
    return TAU*std::sqrt(std::pow(radius1,2)+std::pow(radius2,2))/std::sqrt(2);
}