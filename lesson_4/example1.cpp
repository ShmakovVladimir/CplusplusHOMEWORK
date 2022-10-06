#include <iostream>

struct S1
{
    S1()
    {
        std::cout<<std::endl<<"default constructor"; //вызван конструктор по умолчанию
    }
    S1(int alpha): alpha { alpha }
    {
        std::cout<<std::endl<<"constructor 2"; //вызван конструктор 2 - не по умолчанию
    }

    int alpha;
};
struct S2
{
    // S2(S1 someData)
    // {
    //     this->someData = someData;
    // }
    S2(S1 someData): someData {someData}
    {

    }
    S1 someData;
};

int main()
{
    S1 a(20);
    S2 b(a);
    return 0;
}