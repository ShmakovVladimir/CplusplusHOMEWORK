#pragma once
#include <iostream>
class Complex
{
    public:
        Complex(double alpha,double betta);
        Complex();
        void print() const;
        Complex getMirrored() const;
        Complex operator+(const Complex& numberToAdd) const;
        Complex operator+(double numberToAdd) const;
        Complex operator*(double numberToMult) const;
        double alpha;
        double betta;
};