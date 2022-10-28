#include "fraction.h"

Fraction::Fraction(int a,unsigned int b): numerator{a},denominator{b}
{

}

Fraction::Fraction(): numerator{0},denominator{1}
{

}

Fraction::Fraction(const Fraction& fractionToCopy): numerator{fractionToCopy.numerator},denominator{fractionToCopy.denominator}
{

}

Fraction::Fraction(int a): numerator{a} , denominator{1}
{

}



// Fraction Fraction::operator+(const Fraction& fractionToAdd) const
// {
//     int resultNumerator = numerator*fractionToAdd.denominator+denominator*fractionToAdd.numerator;
//     unsigned int resultDenomenator = denominator*fractionToAdd.denominator;
//     return Fraction(resultNumerator,resultDenomenator).reduceFraction();
// }

Fraction operator+(const Fraction& fractionLeft,const Fraction& fractionRight)
{
   int resultNumerator = fractionLeft.numerator*fractionRight.denominator + fractionLeft.denominator*fractionRight.numerator;
   unsigned int resultDenominator = fractionLeft.denominator*fractionRight.denominator;
   return Fraction(resultNumerator,resultDenominator).reduceFraction(); 
}

Fraction operator-(const Fraction& fractionLeft,const Fraction& fractionRight)
{
    int resultNumerator = fractionLeft.numerator*fractionRight.denominator - fractionLeft.denominator*fractionRight.numerator;
    unsigned int resultDenominator = fractionLeft.denominator*fractionRight.denominator;
    return Fraction(resultNumerator,resultDenominator);
}

std::ostream& operator<<(std::ostream& outObj,const Fraction& fractionToPrint)
{
    outObj<<fractionToPrint.numerator<<" / "<<fractionToPrint.denominator;
    return outObj;
}

std::istream& operator>>(std::istream& inObj,Fraction& fractionToInput)
{
    inObj>>fractionToInput.numerator;
    inObj>>fractionToInput.denominator;
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
Fraction operator*(const Fraction& fractionLeft,const Fraction& fractionRight)
{
    return Fraction(fractionLeft.numerator*fractionRight.numerator,fractionLeft.denominator*fractionRight.denominator).reduceFraction();
}

Fraction operator/(const Fraction& fractionLeft,const Fraction& fractionRight)
{
    return fractionLeft*(fractionRight.getInverced());
}

Fraction& Fraction::reduceFraction()
{
    int nod = gcd(std::abs(numerator),denominator);
    numerator/=nod;
    denominator/=nod;
    return *this;
}

int Fraction::gcd(int a, int b)
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

int Fraction::sign(int a)
{
    // if(a == 0)
    //     return 0;
    return std::abs(a)/a;
}
bool operator==(const Fraction& fraction1,const Fraction& fraction2)
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

Fraction& Fraction::operator+=(const Fraction& fracitonToAdd)
{
    (*this) = (*this)+fracitonToAdd;
    return (*this);
}

Fraction& Fraction::operator-=(const Fraction& fractionToSub)
{
    (*this) = (*this) - fractionToSub;
    return (*this);
}

Fraction& Fraction::operator++()
{
    numerator+=denominator;
    return this->reduceFraction();
}

Fraction& Fraction::operator--()
{
    numerator-=denominator;
    return this->reduceFraction();
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    --(*this);
    return temp;
}

Fraction& Fraction::operator=(const Fraction& fractionToAssign)
{
    numerator = fractionToAssign.numerator;
    denominator = fractionToAssign.denominator;
    return (*this);
}

Fraction Fraction::getInverced() const
{
    if(!numerator)
    {
        std::cerr<<"Zero devision error";
        abort();
    }
    Fraction invFraction = Fraction(denominator,numerator);
    return invFraction;
}
// Fraction& Fraction::operator=(int a)
// {
//     numerator = a;
//     denominator = 1;
//     return (*this);
// }

Fraction::operator double() const
{
    return ((double) numerator)/denominator;
}
