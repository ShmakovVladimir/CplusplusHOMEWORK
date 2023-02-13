#include "vector.hpp"
#include <iostream>



int main()
{
    Vector<int> myArray(1);
    myArray.push(20);
    // myArray.push(100);
    // myArray.push(200);
    std::cout<<myArray;

    return 0;
}