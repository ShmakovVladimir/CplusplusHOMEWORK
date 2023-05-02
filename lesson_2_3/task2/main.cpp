#include "logDuration.hpp"
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <string>


template <typename container>
void SortFunction(container& containerToSort, const std::string& containerName)
{
    LogDuration lg(containerName + "-std::sort");
    std::sort(containerToSort.begin(), containerToSort.end());
}

template <typename container>
void SortMethod(container& containerToSort, const std::string& containerName)
{
    LogDuration lg(containerName + ".sort()");
    containerToSort.sort();
}


int main(int argc, char** argv)
{   
    const std::size_t length = (atoi(argv[1]));
    std::vector<int> startVector(length);
    std::generate(startVector.begin(), startVector.end(), rand);

    // сортировка вектора
    std::vector<int> v(startVector);
    SortFunction<std::vector<int>>(v, "vector");

    //array - никак не получается привести length к константе.
    // перепробовал всё

    //deque

    std::deque<int> deq(startVector.begin(), startVector.end());
    SortFunction<std::deque<int>>(deq, "deque");

    // list
    std::list<int> l{startVector.cbegin(), startVector.cend()};
    SortMethod<std::list<int>>(l, "list");

    // forward_list
    std::forward_list<int> fl{startVector.cbegin(), startVector.cend()};
    SortMethod<std::forward_list<int>>(fl, "forward_list");



    return 0;
}