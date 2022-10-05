#include <iostream>

enum class Month
{
    January,
    March,
    May,
    February,
    April,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};


int getMonthDays(Month month)
{
    switch (month)
    {
    case Month::March:
    case Month::May:
    case Month::July:
    case Month::August:
    case Month::October:
    case Month::December:
    case Month::January:
        return 31;
    case Month::February:
        return 28;
    case Month::June:
    case Month::September:
    case Month::November:
    case Month::April:
        return 30;
    default:
        return -1;
    }
}


int main()
{
    std::cout<<getMonthDays(Month::December)<<std::endl<<getMonthDays(Month::November)<<std::endl<<getMonthDays(Month::September);
    return 0;
}
