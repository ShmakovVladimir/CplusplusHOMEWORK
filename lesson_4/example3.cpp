#include <iostream>
struct DateTime
{
    void printDateAndTime() const
    {
        std::cout<<this->date<<"."<<this->month<<"."<<this->year<<"\t"<<this->hour<<"::"<<this->min<<"::"<<this->second;
    }
    unsigned int year: 12;
    unsigned int month: 4;
    unsigned int date: 5;
    unsigned int hour: 5;
    unsigned int min: 6;
    unsigned int second: 6;
};

int main()
{
    DateTime time = {2022,10,2,5,8,0};
    std::cout<<sizeof(time);
    return 0;
}