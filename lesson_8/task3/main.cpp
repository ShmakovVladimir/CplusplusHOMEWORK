#include "fraction.hpp"

bool opFromList(char op)
{
    return op =='+' || op == '-' || op == '/' || op == '*';
}

Fraction op(char op,const Fraction& fractionLeft,const Fraction& fractionRight)
{
    if(op == '+')
        return fractionLeft+fractionRight;
    if(op == '-')
        return fractionLeft-fractionRight;
    if(op == '*')
        return fractionLeft*fractionRight;
    if(op == '/')
        return fractionLeft/fractionRight;
}

int main()
{
    Fraction fraction1,fraction2;
    bool enter = true;
    char operation;
    while(enter){
        try
        {
            std::cout<<"Enter fraction1: ";
            std::cin>>fraction1;
            std::cout<<"Enter fraction2: ";
            std::cin>>fraction2;
            std::cout<<"Enter the operation(you can choose from +,-,*,/): ";
            std::cin>>operation;
            if(!opFromList(operation))
                throw std::invalid_argument("Please, choose the operation from list");
            std::cout<<std::endl<<"Result is:"<<"\t"<<op(operation, fraction1, fraction2)<<std::endl;
            enter = false;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            std::cout<< "Check your input, and try again"<<std::endl;
        }
    }
    return 0;
}