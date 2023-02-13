#include "fraction.hpp"

Fraction::Fraction(int a,unsigned int b) noexcept(false): numerator{a},denominator{b}
{
    if(!denominator)
        throw FractionException("ZERO DIVISION ERROR");
}

Fraction::Fraction() noexcept: numerator{0},denominator{1}
{

}

Fraction::Fraction(const Fraction& fractionToCopy) noexcept: numerator{fractionToCopy.numerator},denominator{fractionToCopy.denominator}
{

}

Fraction::Fraction(int a) noexcept: numerator{a} , denominator{1}
{

}



// Fraction Fraction::operator+(const Fraction& fractionToAdd) const
// {
//     int resultNumerator = numerator*fractionToAdd.denominator+denominator*fractionToAdd.numerator;
//     unsigned int resultDenomenator = denominator*fractionToAdd.denominator;
//     return Fraction(resultNumerator,resultDenomenator).reduceFraction();
// }

Fraction operator+(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept
{
   int resultNumerator = fractionLeft.numerator*fractionRight.denominator + fractionLeft.denominator*fractionRight.numerator;
   unsigned int resultDenominator = fractionLeft.denominator*fractionRight.denominator;
   return Fraction(resultNumerator,resultDenominator).reduceFraction(); 
}

Fraction operator-(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept
{
    int resultNumerator = fractionLeft.numerator*fractionRight.denominator - fractionLeft.denominator*fractionRight.numerator;
    unsigned int resultDenominator = fractionLeft.denominator*fractionRight.denominator;
    return Fraction(resultNumerator,resultDenominator);
}

std::ostream& operator<<(std::ostream& outObj,const Fraction& fractionToPrint) noexcept
{
    outObj<<fractionToPrint.numerator<<" / "<<fractionToPrint.denominator;
    return outObj;
}

std::istream& operator>>(std::istream& inObj,Fraction& fractionToInput) noexcept(false)
{
    inObj>>fractionToInput.numerator;
    inObj>>fractionToInput.denominator;
    if(!fractionToInput.denominator)
        throw FractionException("ZERO DIVISION ERROR");
    return inObj;
}

// Fraction Fraction::operator-(const Fraction& fractionToSub) const
// {
//     unsigned int resultDenominator = denominator*fractionToSub.denominator;
//     int resultNumerator = numerator*fractionToSub.denominator - fractionToSub.numerator*denominator;
//     return Fraction(resultNumerator,resultDenominator).reduceFraction();
    
// }

// Fraction Fraction::operator*(const Fraction& fractionToMult) const
// {
//     int resultNumerator = numerator*fractionToMult.numerator;
//     unsigned int resultDenumerator = denominator*fractionToMult.denominator;
//     return Fraction(resultNumerator,resultDenumerator).reduceFraction();
// }
Fraction operator*(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept
{
    return Fraction(fractionLeft.numerator*fractionRight.numerator,fractionLeft.denominator*fractionRight.denominator).reduceFraction();
}

Fraction operator/(const Fraction& fractionLeft,const Fraction& fractionRight) noexcept(false)
{
    return fractionLeft*(fractionRight.getInverced());
}

Fraction& Fraction::reduceFraction() noexcept
{
    int nod = gcd(std::abs(numerator),denominator);
    numerator/=nod;
    denominator/=nod;
    return *this;
}

int Fraction::gcd(int a, int b) noexcept
{
      
    while(a!=0 && b!=0)
    {
        if(a>b)
            a=a%b;
        else 
            b=b%a;  
    }
    return (a+b);
}

int Fraction::sign(int a) noexcept
{
    // if(a == 0)
    //     return 0;
    return std::abs(a)/a;
}
bool operator==(const Fraction& fraction1,const Fraction& fraction2) noexcept
{
    return (fraction1.numerator == fraction2.numerator && fraction1.denominator == fraction2.denominator);
}


// Fraction& operator+=(Fraction& fractionLeft,const Fraction& fractionRight)
// {
//     fractionLeft = fractionLeft+fractionRight;
//     return fractionLeft;
// }

// Fraction& operator-=(Fraction& fractionLeft,const Fraction& fractionRight)
// {
//     fractionLeft = fractionLeft-fractionRight;
//     return fractionLeft;
// }

Fraction& Fraction::operator+=(const Fraction& fracitonToAdd) noexcept
{
    (*this) = (*this)+fracitonToAdd;
    return (*this);
}

Fraction& Fraction::operator-=(const Fraction& fractionToSub) noexcept
{
    (*this) = (*this) - fractionToSub;
    return (*this);
}

Fraction& Fraction::operator++() noexcept
{
    numerator+=denominator;
    return this->reduceFraction();
}

Fraction& Fraction::operator--() noexcept
{
    numerator-=denominator;
    return this->reduceFraction();
}

Fraction Fraction::operator++(int) noexcept
{
    Fraction temp(*this);
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int) noexcept
{
    Fraction temp(*this);
    --(*this);
    return temp;
}

Fraction& Fraction::operator=(const Fraction& fractionToAssign) noexcept
{
    numerator = fractionToAssign.numerator;
    denominator = fractionToAssign.denominator;
    return (*this);
}

Fraction Fraction::getInverced() const 
{
    if(!numerator)
        throw FractionException("ZERO DIVISION ERROR");
    Fraction invFraction = Fraction(denominator,numerator);
    return invFraction;
}
// Fraction& Fraction::operator=(int a)
// {
//     numerator = a;
//     denominator = 1;
//     return (*this);
// }

Fraction::operator double() const noexcept
{
    return ((double) numerator)/denominator;
}
