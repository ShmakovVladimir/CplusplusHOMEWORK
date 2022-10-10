#include "complex.h"


void Complex::print() const
{
    std::cout<<alpha<<" + "<<betta<<"*i";
}
Complex::Complex(double alpha,double betta): alpha{alpha},betta{betta}
{

}
Complex::Complex(): alpha {0},betta {0}
{
    
}
Complex Complex::getMirrored() const
{
    return Complex(alpha,-1*betta);
}
Complex Complex::operator+(const Complex& numberToAdd) const
{
    return Complex(alpha+numberToAdd.alpha,betta+numberToAdd.betta);
}
Complex Complex::operator+(const double& numberToAdd) const
{
    return Complex(alpha+numberToAdd,betta);
}
Complex Complex::operator*(const double& numberToMult) const
{
    return Complex(alpha*numberToMult,betta*numberToMult);
}
double Complex::getAlpha() const
{
    return alpha;
}
double Complex::getBetta() const
{
    return betta;
}
void Complex::setAlpha(const double& newAlpha)
{
    alpha = newAlpha;
}
void Complex::setBetta(const double& newBetta)
{
    betta = newBetta;
}
