#pragma once
#include <iostream>
#include <math.h>


class Fraction
{
    public:
        Fraction(int a,unsigned int b);
        Fraction();
        Fraction(const Fraction& fractionToCopy);
        Fraction(int a);
        Fraction operator+(const Fraction& fractionToAdd) const;
        friend std::ostream& operator<<(std::ostream& outObj,const Fraction& fractionToPrint);
        friend std::istream& operator>>(std::istream& inObj,Fraction& fractionToInput);
        Fraction operator-(const Fraction& fractionToSub) const;
        Fraction operator*(const Fraction& fractionToMult) const;
        friend bool operator==(const Fraction& fraction1,const Fraction& fraction2);
        friend Fraction& operator+=(Fraction& fractionLeft,const Fraction& fractionRight);
        friend Fraction& operator-=(Fraction& fractionLeft,const Fraction& fractionRight);
        Fraction& operator=(const Fraction& fractionToAssign);
        Fraction& operator=(int a);
        Fraction& operator++();
        Fraction operator++(int);
        operator double() const;
    private:
        int numerator;
        unsigned int denominator;
        Fraction& reduceFraction();
        static int gcd(int a , int b);
        static int sign(int a);
        
};