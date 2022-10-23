#include <iostream>
#include <vector>
#include "task.h"



int main()
{
    int length = 3;
    int* alpha = new int[length];
    int length2 = 6;
    int* beta = new int[6];
    for(int i = 0;i<length;i++)
        alpha[i] = i*10;
    for(int i = 0; i<length2;i++)
        beta[i] = (i+1)*5;
    
    Task o1(length,alpha);
    std::cout<<o1;
    Task o2 = std::move(o1);
    std::cout<<std::endl<<o2;
    std::cout<<std::endl<<o1;
    o1 = o2;
    std::cout<<std::endl<<o1;
    std::cout<<std::endl<<o2;
    o1 = std::move(o2);
    std::cout<<std::endl<<o1;
    std::cout<<std::endl<<o2;
    o1 = Task(length,alpha);
    std::cout<<std::endl<<o1;
    delete[] alpha;
    delete[] beta;
    return 0;
}