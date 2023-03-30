#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "logDuration.hpp"

void appendToSet(const std::vector<int> &startVector, std::set<int> &mySet)
{
    LogDuration lg("");
    for(auto num: startVector)
        mySet.insert(num);
}


int main(int argc, char** argv)
{
    const std::size_t length = (atoi(argv[1]));
    std::vector<int> startVector(length);
    std::generate(startVector.begin(), startVector.end(), rand);
    std::set<int> mySet;
    appendToSet(startVector, mySet);

    return 0;
}