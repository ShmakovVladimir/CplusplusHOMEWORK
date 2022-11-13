#include <iostream>
#include <stdlib.h>
 #include <variant>

enum class ErrorCodes
{
    LEFT_INDEX_OUT_OF_RANGE = -1,
    RIGHT_INDEX_OUT_OF_RANGE = -2,
    NO_ERROR = -3
};

struct functionResult
{
    int middleIndex;
    ErrorCodes errorCode;
};


//Код ошибки через enum
int getMiddleIndex_simplest(int leftIndex,int rightIndex,int arrayLength)
{
    if(leftIndex<0 || leftIndex>=arrayLength)
        return (int)ErrorCodes::LEFT_INDEX_OUT_OF_RANGE;
    if(rightIndex < 0 || rightIndex>=arrayLength)
        return (int)ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE;
    return leftIndex + (rightIndex-leftIndex)/2;
}

void enumErrorExample()
{
    int left,right,arrayLength;
    std::cout<<"Please, enter the array's length: ";
    std::cin>>arrayLength;
    std::cout<<std::endl<<"Enter the left index: ";
    std::cin>>left;
    std::cout<<std::endl<<"Enter the right index: ";
    std::cin>>right;
    int middleIndex = getMiddleIndex_simplest(left,right,arrayLength);
    if(middleIndex == (int)ErrorCodes::LEFT_INDEX_OUT_OF_RANGE)
    {
        std::cerr<<"Left index out of range error";
        std::exit(-1);
    }
    if(middleIndex == (int)ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE)
    {
        std::cerr<<"Right index out of range error";
        std::exit(-1);
    }
    std::cout<<std::endl<<"The middle index is: "<<middleIndex;
}

//возвращаем структуру, содержащую результат выполнения и код ошибки
functionResult getMiddleIndex_errorCodeInStruct(int leftIndex,int rightIndex,int arrayLength)
{
    if(leftIndex < 0 || leftIndex >= arrayLength)
        return {0,ErrorCodes::LEFT_INDEX_OUT_OF_RANGE};
    if(rightIndex < 0 || rightIndex >= arrayLength)
        return {0,ErrorCodes::LEFT_INDEX_OUT_OF_RANGE};
    return {leftIndex + (rightIndex-leftIndex)/2,ErrorCodes::NO_ERROR};
}

void errorInStructExample()
{
    int left,right,arrayLength;
    std::cout<<"Please, enter the array's length: ";
    std::cin>>arrayLength;
    std::cout<<std::endl<<"Enter the left index: ";
    std::cin>>left;
    std::cout<<std::endl<<"Enter the right index: ";
    std::cin>>right;
    auto middle_index = getMiddleIndex_errorCodeInStruct(left,right,arrayLength);
    switch (middle_index.errorCode)
    {
    case ErrorCodes::LEFT_INDEX_OUT_OF_RANGE:
        std::cout<<std::endl<<"Left index out of range: ";
        std::exit(-1);
    case ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE:
        std::cout<<std::endl<<"Right index out of range: ";
        std::exit(-1);
    case ErrorCodes::NO_ERROR:
        std::cout<<std::endl<<"Middle index is: "<<middle_index.middleIndex;
        break;
    default:
        break;
    }
}

std::variant<ErrorCodes, int> getMiddleIndex_variant(int leftIndex,int rightIndex, int arrayLength)
{
    if(leftIndex < 0 || leftIndex >= arrayLength)
        return ErrorCodes::LEFT_INDEX_OUT_OF_RANGE;
    if(rightIndex < 0 || rightIndex >= arrayLength)
        return ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE;
    return leftIndex + (rightIndex - leftIndex)/2;
}

void variantError()
{
    int left,right,arrayLength;
    std::cout<<"Please, enter the array's length: ";
    std::cin>>arrayLength;
    std::cout<<std::endl<<"Enter the left index: ";
    std::cin>>left;
    std::cout<<std::endl<<"Enter the right index: ";
    std::cin>>right;
    auto middleIndex = getMiddleIndex_variant(left,right,arrayLength);
    auto* error = std::get_if<ErrorCodes>(&middleIndex);
    if(!error)
        std::cout<<std::endl<<"middle index is: "<<std::get<int>(middleIndex);
    else
    {
        switch (*error)
        {
        case ErrorCodes::LEFT_INDEX_OUT_OF_RANGE:
            std::cout<<std::endl<<"Left index out of range";
            std::exit(-1);
        case ErrorCodes::RIGHT_INDEX_OUT_OF_RANGE:
            std::cout<<std::endl<<"Right index out of range";
            std::exit(-1);
        default:
            break;
        }
    }


}





int main()
{
    variantError();
    
    return 0;
}