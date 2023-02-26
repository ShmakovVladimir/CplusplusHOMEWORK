#include <iostream>
#include <vector>
#include "findException.hpp"

// Если элемент искомый элемент присутствует - находит его в массиве и возвращает индекс
// В противном случае - кидает исключение типа BinSearchException
// Шаблон написан плохо, стоило реализовать отдельное инстанирование для float и double
// Так как при их сравнении следует учитывать погрешность
// Если операции <, ==... не определены, тоже выбрасывается исключение
template<typename dataType>
int binarySearch(const std::vector<dataType>& arr, dataType what) noexcept(false)
{
    auto left = arr.cbegin();
    auto right = arr.cend();
    auto mid = left + (right - left)/2;
    while(left <= right)
    {
        mid = left + (right - left)/2;
        if (*mid == what)
            return mid - arr.begin();
        if (*mid < what)
            left = mid + 1;
        else
            right = mid - 1;
    }
    throw BinSearchException("There is no such element in this vector");
}



int main()
{
    std::vector<int> MyVector = {20, 40, 51, 80, 99, 1000, 1002};

    try
    {
        std::cout << binarySearch<int>(MyVector, 20) << std::endl;
        std::cout << binarySearch<int>(MyVector, 1002) << std::endl;
        std::cout << binarySearch<int>(MyVector, 1000) << std::endl;
        std::cout << binarySearch<int>(MyVector, 80) << std::endl;
        std::cout << binarySearch<int>(MyVector, 0) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout<< "Check your input, and try again"<<std::endl;
    }
    // на таком простом тесте всё сработало
    return 0;
}