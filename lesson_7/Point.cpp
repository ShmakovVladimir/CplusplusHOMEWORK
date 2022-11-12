#include "Point.hpp"

double Point::getLength()
{
    return std::sqrt(std::pow(x,2)+std::pow(y,2));
}

std::ostream& operator<<(std::ostream& outObj,const Point& pointToPrint)
{
    outObj<<"x: "<<pointToPrint.x<<" y: "<<pointToPrint.y;
    return outObj;
}