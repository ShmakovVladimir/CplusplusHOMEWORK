#pragma once
#include <iostream>
class Complex
{
    public:
        Complex(float alpha,float betta);
        Complex();
        void print() const;
        Complex getMirrored() const;
        Complex operator+(const Complex& numberToAdd) const;
        Complex operator+(const float& numberToAdd) const;
        Complex operator*(const float& numberToMult) const;
        float getAlpha() const;
        float getBetta() const;
        void setAlpha(const float& newAlpha);
        void setBetta(const float& newBetta);
    private:
        float alpha;
        float betta;
};