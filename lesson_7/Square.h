#pragma once
#include "Rect.h"


class Square: public Rect
{
    public:
        Square(double side,double rotationAngle,Point center);
        virtual double getArea() const final;
        virtual double getPerimetr() const final;
        virtual void print() const final;
};