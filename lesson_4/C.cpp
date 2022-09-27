#include <iostream>

struct dateTime
{
    unsigned int year: 12;
    unsigned int month: 4;
    unsigned int date: 5;
    unsigned int hour: 5;
    unsigned int min: 6;
    unsigned int second: 6;
    void printDateAndTime(){
        std::cout<<this->date<<"."<<this->month<<"."<<this->year<<"\t"<<this->hour<<"::"<<this->min<<"::"<<this->second;
    }
};



int main(){
    dateTime timeIDoMyHomework;
    timeIDoMyHomework.year = 2022;
    timeIDoMyHomework.month = 9;
    timeIDoMyHomework.date = 25;
    timeIDoMyHomework.hour = 2;
    timeIDoMyHomework.min = 32;
    timeIDoMyHomework.second = 60;
    timeIDoMyHomework.printDateAndTime();
    return 0;
}