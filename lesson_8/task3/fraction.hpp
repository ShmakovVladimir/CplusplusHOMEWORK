#pragma once
#include "exceptionClass.hpp"
#include <iostream>
#include <math.h>


class Fraction
{
    public:
        Fraction(int a,unsigned int b) noexcept(false);
        Fraction() noexcept;
        Fraction(const Fraction& fractionToCopy) noexcept;
        Fraction(int a) noexcept;
        // Fraction operator+(const Fraction& fractionToAdd) const;
        friend Fraction operator+(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept;
        friend Fraction operator-(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept;
        friend std::ostream& operator<<(std::ostream& outObj,const Fraction& fractionToPrint) noexcept;
        friend std::istream& operator>>(std::istream& inObj,Fraction& fractionToInput) noexcept(false);
        // Fraction operator-(const Fraction& fractionToSub) const;
        // Fraction operator*(const Fraction& fractionToMult) const;
        friend Fraction operator*(const Fraction& frationLeft,const Fraction& fractionRight) noexcept;
        friend Fraction operator/(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept(false);
        friend bool operator==(const Fraction& fraction1,const Fraction& fraction2) noexcept;
        // friend Fraction& operator+=(Fraction& fractionLeft,const Fraction& fractionRight);
        // friend Fraction& operator-=(Fraction& fractionLeft,const Fraction& fractionRight);
        Fraction& operator+=(const Fraction& fractionToAdd) noexcept;
        Fraction& operator-=(const Fraction& fractionToSub) noexcept;
        Fraction& operator=(const Fraction& fractionToAssign) noexcept;  
        // Fraction& operator=(int a);
        Fraction& operator++() noexcept;
        Fraction operator++(int) noexcept;
        Fraction& operator--() noexcept;
        Fraction operator--(int) noexcept;
        explicit operator double() const noexcept;
    private:
        int numerator;
        unsigned int denominator;
        Fraction& reduceFraction() noexcept;
        Fraction getInverced() const noexcept(false);
        static int gcd(int a , int b) noexcept;
        static int sign(int a) noexcept;
        
};