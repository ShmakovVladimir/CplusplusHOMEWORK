#pragma once
#include <vector>
#include "Point.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

class Figure
{
    public:
        Figure();
        Figure(Point center);
        virtual void print() const = 0;
        virtual double getArea() const = 0;
        virtual double getPerimetr() const = 0;
    protected:
        Point center;
        const static int sides = 500;
        std::vector<Point> points;
};