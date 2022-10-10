#include <iostream>
#include "complex.h"



int main()
{
    Complex alpha(2,3);
    Complex betta(5,7);
    Complex gamma = alpha+betta;
    double r = 90;
    Complex epsilon = gamma+r;
    Complex zetta = alpha*r;
    std::cout<<"alpha: ";
    alpha.print();
    std::cout<<std::endl<<"betta: ";
    betta.print();
    std::cout<<std::endl<<"r: "<<r;
    std::cout<<std::endl<<"gamma = alpha+betta: ";
    gamma.print();
    std::cout<<std::endl<<"epsilon = gamma+r: ";
    epsilon.print();
    std::cout<<std::endl<<"epsilon alpha cff: "<<epsilon.getAlpha();
    std::cout<<std::endl<<"epsilon betta cff: "<<epsilon.getBetta();
    std::cout<<std::endl<<"Setting epsilon alpha cff = r";
    epsilon.setAlpha(r);
    std::cout<<std::endl<<"epsilon alpha cff: "<<epsilon.getAlpha();
    std::cout<<std::endl<<"epsilon betta cff: "<<epsilon.getBetta();
    std::cout<<std::endl<<"zetta = alpha*r: ";
    zetta.print();
    return 0;
}