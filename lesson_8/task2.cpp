#include <iostream>

enum class divErrors
{
    ZERO_DIVISION_ERROR
};

double divOperator(double numerator,double denominator) noexcept(false)
{
    if(denominator == 0)
        throw(divErrors::ZERO_DIVISION_ERROR);
    return numerator/denominator;
}


int main()
{
    bool repeatEntering = 1;
    double numerator,denominator;
    while(repeatEntering)
    {
        std::cout<<"Enter numerator: ";
        std::cin>>numerator;
        std::cout<<"Enter denominator: ";
        std::cin>>denominator;
        try
        {
            double divOperationResult = divOperator(numerator,denominator);
            std::cout<<divOperationResult;
            repeatEntering = false;
        }
        catch(const divErrors& error)
        {
            if(error == divErrors::ZERO_DIVISION_ERROR)
            {
                std::cerr <<"ZERO DIVISION ERROR";
                std::cout<<std::endl<<"Check your input, and try again"<<std::endl;
            }
            else
                std::cerr<<"Unknown Error";
        }
    }
    return 0;
}