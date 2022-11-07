#include "Point.h"

double Point::getLength()
{
    return sqrt(pow(x,2)+pow(y,2));
}

std::ostream& operator<<(std::ostream& outObj,const Point& pointToPrint)
{
    outObj<<"x: "<<pointToPrint.x<<" y: "<<pointToPrint.y;
    return outObj;
}