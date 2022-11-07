#pragma once
#include <math.h>
#include <iostream>

struct Point
{
    double getLength();
    double x,y;
    friend std::ostream& operator<<(std::ostream& outObj,const Point& pointToPrint);
};

