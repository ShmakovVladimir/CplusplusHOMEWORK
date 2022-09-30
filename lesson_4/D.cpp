#include <iostream>

enum Month{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};


int getMonthDays(Month month){
    switch (month)
    {
    case Month::January:
        return 31;
    case Month::February:
        return 28;
    case Month::March:
        return 31;
    case Month::April:
        return 30;
    case Month::May:
        return 31;
    case Month::June:
        return 30;
    case Month::July:
        return 31;
    case Month::August:
        return 31;
    case Month::September:
        return 30;
    case Month::October:
        return 31;
    case Month::November:
        return 30;
    case Month::December:
        return 31;
    }
}


int main(){
    std::cout<<getMonthDays(Month::December)<<std::endl<<getMonthDays(Month::November);
    return 0;
}
