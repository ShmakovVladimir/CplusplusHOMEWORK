#pragma once
#include "Figure.h"
#include "Ellipse.h"

class Circle: public Ellipse
{
    public:
        Circle(Point center,double radius);
        virtual double getArea() const final;
        virtual double getPerimetr() const final;
        virtual void print() const final;
};