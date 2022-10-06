#include <iostream>

struct S
{
    S(int arrLength): arrLength {arrLength}
    {
        std::cout<<std::endl<<"allocating new memory for array";
        this->arr = new int[arrLength];
    }
    ~S()
    {
        std::cout<<std::endl<<"memory cleared";
        delete[] this->arr;
    }
    int arrLength;
    int* arr;
};

int main()
{
    S(20);
    return 0;
}