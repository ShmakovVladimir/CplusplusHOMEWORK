#pragma once
#include "Figure.hpp"

class Ellipse: public Figure
{
    public:
        Ellipse(Point center,double rotationAngle,double radius1,double radius2);
        virtual void print() const override;
        virtual double getArea() const override;
        virtual double getPerimetr() const override;
    protected:
        Point center;
        double radius1;
        double radius2;
        double angle;
};