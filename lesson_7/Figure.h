#pragma once
#include <vector>
#include "Point.h"
#include "windowProp.hpp"
#include <iostream>
#include "MathConstants.hpp"

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