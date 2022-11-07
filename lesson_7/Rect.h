#pragma once
#include "Figure.h"



class Rect: public Figure
{
    public:
        Rect(double sideA,double sideB,double rotationAngle,Point center);
        virtual double getArea() const override;
        virtual double getPerimetr() const override;
        virtual void print() const override;
    protected:
        double sideA;
        double sideB;
        double angle;
    private:
        void generatePoints();
};