#include "complex.h"


void Complex::print() const
{
    std::cout<<this->alpha<<" + "<<this->betta<<"*i";
}
Complex::Complex(float alpha,float betta): alpha{alpha},betta{betta}
{

}
Complex::Complex()
{
    this->alpha = 0;
    this->betta = 0;
}
Complex Complex::getMirrored() const
{
    return Complex(this->alpha,-1*this->betta);
}
Complex Complex::operator+(const Complex& numberToAdd) const
{
    return Complex(this->alpha+numberToAdd.alpha,this->betta+numberToAdd.betta);
}
Complex Complex::operator+(const float& numberToAdd) const
{
    return Complex(this->alpha+numberToAdd,this->betta);
}
Complex Complex::operator*(const float& numberToMult) const
{
    return Complex(this->alpha*numberToMult,this->betta*numberToMult);
}
float Complex::getAlpha() const
{
    return this->alpha;
}
float Complex::getBetta() const
{
    return this->betta;
}
void Complex::setAlpha(const float& newAlpha)
{
    this->alpha = newAlpha;
}
void Complex::setBetta(const float& newBetta)
{
    this->betta = newBetta;
}
