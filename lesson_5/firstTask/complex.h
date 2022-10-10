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
        Complex operator+(const double& numberToAdd) const;
        Complex operator*(const double& numberToMult) const;
        double getAlpha() const;
        double getBetta() const;
        void setAlpha(const double& newAlpha);
        void setBetta(const double& newBetta);
    private:
        double alpha;
        double betta;
};