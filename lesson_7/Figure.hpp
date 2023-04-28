#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include "Point.hpp"
#include <iostream>
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
