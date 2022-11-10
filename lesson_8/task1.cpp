#include <iostream>

enum ErrorCodes
{
    LEFT_INDEX_OUT_OF_RANGE = -1,
    RIGHT_INDEX_OUT_OF_RANGE = -2
};

int getMiddleIndex(int leftIndex,int rightIndex,int arrayLength)
{
    if(leftIndex<0 || leftIndex>=arrayLength)
        return ErrorCodes::LEFT_INDEX_OUT_OF_RANGE;
    if(rightIndex < 0 || rightIndex>=arrayLength)
        return ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE;
    return leftIndex + (rightIndex-leftIndex)/2;
}

int main()
{
    int left,right,arrayLength;
    std::cout<<"Please, enter the array's length: ";
    std::cin>>arrayLength;
    std::cout<<std::endl<<"Enter the left index: ";
    std::cin>>left;
    std::cout<<std::endl<<"Enter the right index: ";
    std::cin>>right;
    int middleIndex = getMiddleIndex(left,right,arrayLength);
    if(middleIndex == ErrorCodes::LEFT_INDEX_OUT_OF_RANGE)
    {
        std::cerr<<"Left index out of range error";
        return 0;
    }
    if(middleIndex == ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE)
    {
        std::cerr<<"Right index out of range error";
        return 0;
    }
    std::cout<<std::endl<<"The middle index is: "<<middleIndex;
    return 0;
}