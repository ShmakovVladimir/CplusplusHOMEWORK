#include <iostream>
#include "fraction.h"




int main()
{
    Fraction alpha;
    Fraction beta;
    Fraction gamma;
    std::cout<<"Enter fraction alpha: ";
    std::cin>>alpha;
    std::cout<<std::endl<<"Enter fraction beta: ";
    std::cin>>beta;
    std::cout<<std::endl<<"Enter fraction gamma: ";
    std::cin>>gamma;
    alpha+=gamma;
    std::cout<<std::endl;
    std::cout<<"alpha+=gamma result: "<<alpha<<std::endl;
    std::cout<<"beta*gamma is: "<<beta*gamma<<std::endl;
    std::cout<<"alpha+beta is: "<<alpha+beta<<std::endl;
    std::cout<<"gamma+alpha is: "<<gamma+alpha<<std::endl;
    std::cout<<"gamma++ is: "<<gamma++<<std::endl;
    std::cout<<"++ gamma is: "<<++gamma<<std::endl;
    std::cout<<std::endl<<std::endl<<std::endl;
    alpha = 1;
    beta = alpha;
    Fraction zetta = 2;
    std::cout<<"New variables values: "<<std::endl;
    std::cout<<"alpha: "<<alpha<<std::endl;
    std::cout<<"beta: "<<beta<<std::endl;
    std::cout<<"gamma: "<<gamma<<std::endl;
    std::cout<<"zetta: "<<zetta<<std::endl;
    std::cout<<"beta*gamma is: "<<beta*gamma<<std::endl;
    std::cout<<"alpha+beta is: "<<alpha+beta<<std::endl;
    std::cout<<"gamma+alpha is: "<<gamma+alpha<<std::endl;
    std::cout<<"gamma++ is: "<<gamma++<<std::endl;
    std::cout<<"++ gamma is: "<<++gamma<<std::endl;
    std::cout<<"gamma to double result is: "<<(double) gamma<<std::endl;
    return 0;
}