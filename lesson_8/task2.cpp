#include <iostream>
#include <cmath>

//std::overflow_error
double divOperator(double numerator, double denominator,double epsilon = std::pow(10,-5))
{
    if(std::abs(denominator) < epsilon)
        throw(std::overflow_error("Zero division"));
    return numerator/denominator;
}

void divisionExample()
{
    int a,b;
    std::cout<<"Enter numerator: ";
    std::cin>>a;
    std::cout<<"Enter denominator: ";
    std::cin>>b;
    try
    {
        double divisionResult = divOperator(a,b);
        std::cout<<std::endl<<"Result is: "<<divisionResult;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Division error: " << e.what();
    }
    
}

//out of range,length error
int getMiddleIndex(int leftIndex,int rightIndex,int arrayLength)
{
    if(arrayLength<=0)
        throw std::length_error("Wrong arrayLength");
    if(leftIndex < 0 || leftIndex >= arrayLength)
        throw std::out_of_range("Left index out of range");
    if(rightIndex < 0 || rightIndex >= arrayLength)
        throw std::out_of_range("Right index out of range");
    return leftIndex + (rightIndex-leftIndex)/2;
}

// проблема с выделением памяти - bad_alloc
void veryBigArray()
{
    const unsigned long long int veryBigNumber = std::pow(10,8);
    double** arr = new double*[veryBigNumber];
    try
    {
       for(int i = 0;i<veryBigNumber;i++)
       {
            arr[i] = new double[veryBigNumber];
            std::cout<<std::endl<<i;
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Problem: "<< e.what();
    }
    
}

void MiddleIndexExample()
{
    int left,right,arrLength;
    std::cout<<"Enter the array length: ";
    std::cin>>arrLength;
    std::cout<<"Enter the left index: ";
    std::cin>>left;
    std::cout<<"Enter the right index: ";
    std::cin>>right;
    try
    {
        int middleIndex = getMiddleIndex(left,right,arrLength);
        std::cout<<std::endl<<"Middle index is: "<<middleIndex;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Problems: " << e.what();
    }
    
}

int main()
{
    // divisionExample();
    // MiddleIndexExample();
    veryBigArray();
    return 0;
}