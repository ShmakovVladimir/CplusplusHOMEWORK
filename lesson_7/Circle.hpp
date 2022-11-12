#pragma once
#include "Figure.hpp"
#include "Ellipse.hpp"

class Circle: public Ellipse
{
    public:
        Circle(Point center,double radius);
        // virtual double getArea() const final;
        // virtual double getPerimetr() const final;
        virtual void print() const final;
};